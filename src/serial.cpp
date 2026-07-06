#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"
#include "ciphertext-ser.h"
#include "cryptocontext-ser.h"
#include "key/key-ser.h"
#include "scheme/bfvrns/bfvrns-ser.h"
#include "scheme/bgvrns/bgvrns-ser.h"
#include "scheme/ckksrns/ckksrns-ser.h"

#include "openfhe_julia/jlcxx_parameters.h"

void wrap_SerType(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::SerType::SERJSON>("SERJSON");
  mod.add_type<lbcrypto::SerType::SERBINARY>("SERBINARY");
}

void wrap_Serial(jlcxx::Module& mod) {
  // Source: <OpenFHE>/src/core/include/utils/serial.h
  //
  // The serialization functions are function templates, so we use lambdas to force instantiation
  // (the call in the lambda body deduces T). An alternative is explicit
  // template arguments, as done for GenCryptoContext in cryptocontextimpl.cpp:
  //
  //   mod.method("SerializeToFile", &lbcrypto::Serial::SerializeToFile<CT>);
  //
  // However, SerializeToFile is overloaded on the SerType parameter (SERBINARY
  // vs SERJSON), so the above is ambiguous — you'd also need a static_cast to
  // pick the right overload. The full working alternative would be:
  //
  //   mod.method("SerializeToFile",
  //       static_cast<bool (*)(const std::string&, const CT&,
  //                            const lbcrypto::SerType::SERBINARY&)>(
  //           &lbcrypto::Serial::SerializeToFile<CT>));
  //
  // The lambda avoids both problems at once and is less obscure.
  using DCRTPoly    = lbcrypto::DCRTPoly;
  using CC          = lbcrypto::CryptoContext<DCRTPoly>;
  using CT          = lbcrypto::Ciphertext<DCRTPoly>;
  using PK          = lbcrypto::PublicKey<DCRTPoly>;
  using SK          = lbcrypto::PrivateKey<DCRTPoly>;
  using SerBin      = lbcrypto::SerType::SERBINARY;
  using SerJSON     = lbcrypto::SerType::SERJSON;

  // ── SerializeToString / DeserializeFromString (JSON) ───────────────────────

  mod.method("SerializeToString", [](const CT& obj) {
    return lbcrypto::Serial::SerializeToString(obj);
  });
  mod.method("SerializeToString", [](const CC& obj) {
    return lbcrypto::Serial::SerializeToString(obj);
  });
  mod.method("SerializeToString", [](const PK& obj) {
    return lbcrypto::Serial::SerializeToString(obj);
  });
  mod.method("SerializeToString", [](const SK& obj) {
    return lbcrypto::Serial::SerializeToString(obj);
  });

  mod.method("DeserializeFromString", [](CT& obj, const std::string& json) {
    lbcrypto::Serial::DeserializeFromString(obj, json);
  });
  mod.method("DeserializeFromString", [](CC& obj, const std::string& json) {
    lbcrypto::Serial::DeserializeFromString(obj, json);
  });
  mod.method("DeserializeFromString", [](PK& obj, const std::string& json) {
    lbcrypto::Serial::DeserializeFromString(obj, json);
  });
  mod.method("DeserializeFromString", [](SK& obj, const std::string& json) {
    lbcrypto::Serial::DeserializeFromString(obj, json);
  });

  // ── EvalKey serialization (eval mult + automorphism keys) ─────────────────
  //
  // Eval keys (multiplication/relinearization and automorphism/rotation) are
  // stored in static maps inside CryptoContextImpl, separate from the
  // CryptoContext itself.  SerializeToString/DeserializeFromString do not
  // cover them — they need their own serialize/deserialize path.

  mod.method("SerializeEvalMultKeyToString", [](const CC& cc) -> std::string {
    std::ostringstream oss;
    if (!lbcrypto::CryptoContextImpl<DCRTPoly>::SerializeEvalMultKey(oss, SerBin{}, cc)){
      return "";
    } else {
      return oss.str();
    }
  });

  // We reimplement DeserializeEvalMultKey rather than calling
  // CryptoContextImpl::DeserializeEvalMultKey directly because the upstream
  // InsertEvalMultKey throws when keys for a given tag already exist.
  // In downstream SecureArithmetic, the same SecureContext is serialized redundantly. 
  // Once standalone and once embedded in every SecureArray, PublicKey, etc.  
  // So the same eval keys are deserialized multiple times in one session.
  // We skip tags that are already present to make deserialization idempotent.
  mod.method("DeserializeEvalMultKeyFromString", [](const std::string& data) -> bool {
    std::istringstream iss(data);
    std::map<std::string, std::vector<lbcrypto::EvalKey<DCRTPoly>>> omap;
    lbcrypto::Serial::Deserialize(omap, iss, SerBin{});
    const auto& existing = lbcrypto::CryptoContextImpl<DCRTPoly>::GetAllEvalMultKeys();
    for (auto& [tag, vec] : omap) {
      if (existing.find(tag) == existing.end()){  // tag not present 
        lbcrypto::CryptoContextImpl<DCRTPoly>::InsertEvalMultKey(vec, tag);
      }
    }
    return true;
  });

  mod.method("SerializeEvalAutomorphismKeyToString", [](const CC& cc) -> std::string {
    std::ostringstream oss;
    if (!lbcrypto::CryptoContextImpl<DCRTPoly>::SerializeEvalAutomorphismKey(oss, SerBin{}, cc)){
      return "";
    } else {
      return oss.str();
    }
  });

  // Same idempotent approach as DeserializeEvalMultKeyFromString above —
  // skip tags that already have entries in the global automorphism key map.
  mod.method("DeserializeEvalAutomorphismKeyFromString", [](const std::string& data) -> bool {
    std::istringstream iss(data);
    std::map<std::string, std::shared_ptr<std::map<uint32_t, lbcrypto::EvalKey<DCRTPoly>>>> keyMap;
    lbcrypto::Serial::Deserialize(keyMap, iss, SerBin{});
    const auto& existing = lbcrypto::CryptoContextImpl<DCRTPoly>::GetAllEvalAutomorphismKeys();
    for (auto& [tag, mapPtr] : keyMap) {
      if (existing.find(tag) == existing.end()){
        lbcrypto::CryptoContextImpl<DCRTPoly>::InsertEvalAutomorphismKey(mapPtr, tag);
      }
    }
    return true;
  });

  // ── SerializeToFile / DeserializeFromFile (BINARY) ────────────────────────

  mod.method("SerializeToFile", [](const std::string& filename, const CT& obj, const SerBin& st) {
    return lbcrypto::Serial::SerializeToFile(filename, obj, st);
  });
  mod.method("SerializeToFile", [](const std::string& filename, const CC& obj, const SerBin& st) {
    return lbcrypto::Serial::SerializeToFile(filename, obj, st);
  });
  mod.method("SerializeToFile", [](const std::string& filename, const PK& obj, const SerBin& st) {
    return lbcrypto::Serial::SerializeToFile(filename, obj, st);
  });
  mod.method("SerializeToFile", [](const std::string& filename, const SK& obj, const SerBin& st) {
    return lbcrypto::Serial::SerializeToFile(filename, obj, st);
  });

  mod.method("DeserializeFromFile", [](const std::string& filename, CT& obj, const SerBin& st) {
    return lbcrypto::Serial::DeserializeFromFile(filename, obj, st);
  });
  mod.method("DeserializeFromFile", [](const std::string& filename, CC& obj, const SerBin& st) {
    return lbcrypto::Serial::DeserializeFromFile(filename, obj, st);
  });
  mod.method("DeserializeFromFile", [](const std::string& filename, PK& obj, const SerBin& st) {
    return lbcrypto::Serial::DeserializeFromFile(filename, obj, st);
  });
  mod.method("DeserializeFromFile", [](const std::string& filename, SK& obj, const SerBin& st) {
    return lbcrypto::Serial::DeserializeFromFile(filename, obj, st);
  });

  // ── SerializeToFile / DeserializeFromFile (JSON) ──────────────────────────

  mod.method("SerializeToFile", [](const std::string& filename, const CT& obj, const SerJSON& st) {
    return lbcrypto::Serial::SerializeToFile(filename, obj, st);
  });
  mod.method("SerializeToFile", [](const std::string& filename, const CC& obj, const SerJSON& st) {
    return lbcrypto::Serial::SerializeToFile(filename, obj, st);
  });
  mod.method("SerializeToFile", [](const std::string& filename, const PK& obj, const SerJSON& st) {
    return lbcrypto::Serial::SerializeToFile(filename, obj, st);
  });
  mod.method("SerializeToFile", [](const std::string& filename, const SK& obj, const SerJSON& st) {
    return lbcrypto::Serial::SerializeToFile(filename, obj, st);
  });

  mod.method("DeserializeFromFile", [](const std::string& filename, CT& obj, const SerJSON& st) {
    return lbcrypto::Serial::DeserializeFromFile(filename, obj, st);
  });
  mod.method("DeserializeFromFile", [](const std::string& filename, CC& obj, const SerJSON& st) {
    return lbcrypto::Serial::DeserializeFromFile(filename, obj, st);
  });
  mod.method("DeserializeFromFile", [](const std::string& filename, PK& obj, const SerJSON& st) {
    return lbcrypto::Serial::DeserializeFromFile(filename, obj, st);
  });
  mod.method("DeserializeFromFile", [](const std::string& filename, SK& obj, const SerJSON& st) {
    return lbcrypto::Serial::DeserializeFromFile(filename, obj, st);
  });
}
