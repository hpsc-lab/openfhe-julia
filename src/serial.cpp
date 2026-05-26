#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"
#include "cryptocontext-ser.h"

#include "openfhe_julia/jlcxx_parameters.h"

void wrap_SerType(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::SerType::SERJSON>("SERJSON");
  mod.add_type<lbcrypto::SerType::SERBINARY>("SERBINARY");
}

void wrap_Serial(jlcxx::Module& mod) {
  // Source: <OpenFHE>/src/core/include/utils/serial.h
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
