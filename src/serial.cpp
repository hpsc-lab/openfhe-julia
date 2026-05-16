#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"
#include "cryptocontext-ser.h"
#include "ciphertext-ser.h"
#include "key/key-ser.h"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

// SERBINARY and SERJSON are empty structs; jlcxx treats them as "mirrored"
// (mapped directly to Julia bits types) by default, which prevents add_type.
// Opt them out so they can be exposed as proper Julia wrapper types.
namespace jlcxx {
  template<> struct IsMirroredType<lbcrypto::SerType::SERBINARY> : std::false_type {};
  template<> struct IsMirroredType<lbcrypto::SerType::SERJSON>   : std::false_type {};
}

void wrap_Serial(jlcxx::Module& mod) {
  // Source: <OpenFHE>/src/core/include/utils/serial.h
  using DCRTPoly    = lbcrypto::DCRTPoly;
  using CC          = lbcrypto::CryptoContext<DCRTPoly>;
  using CCImpl      = lbcrypto::CryptoContextImpl<DCRTPoly>;
  using CT          = lbcrypto::Ciphertext<DCRTPoly>;
  using PK          = lbcrypto::PublicKey<DCRTPoly>;
  using SK          = lbcrypto::PrivateKey<DCRTPoly>;
  using BINARY      = lbcrypto::SerType::SERBINARY;
  using JSON        = lbcrypto::SerType::SERJSON;

  mod.add_type<BINARY>("SERBINARY");
  mod.add_type<JSON>("SERJSON");

  // ── SerializeToFile ─────────────────────────────────────────────────────────

  mod.method("SerializeToFile", [](const std::string& f, const CT& obj, const BINARY& st) {
    return lbcrypto::Serial::SerializeToFile(f, obj, st);
  });
  mod.method("SerializeToFile", [](const std::string& f, const CT& obj, const JSON& st) {
    return lbcrypto::Serial::SerializeToFile(f, obj, st);
  });

  mod.method("SerializeToFile", [](const std::string& f, const CC& obj, const BINARY& st) {
    return lbcrypto::Serial::SerializeToFile(f, obj, st);
  });
  mod.method("SerializeToFile", [](const std::string& f, const CC& obj, const JSON& st) {
    return lbcrypto::Serial::SerializeToFile(f, obj, st);
  });

  mod.method("SerializeToFile", [](const std::string& f, const PK& obj, const BINARY& st) {
    return lbcrypto::Serial::SerializeToFile(f, obj, st);
  });
  mod.method("SerializeToFile", [](const std::string& f, const PK& obj, const JSON& st) {
    return lbcrypto::Serial::SerializeToFile(f, obj, st);
  });

  mod.method("SerializeToFile", [](const std::string& f, const SK& obj, const BINARY& st) {
    return lbcrypto::Serial::SerializeToFile(f, obj, st);
  });
  mod.method("SerializeToFile", [](const std::string& f, const SK& obj, const JSON& st) {
    return lbcrypto::Serial::SerializeToFile(f, obj, st);
  });

  // ── DeserializeFromFile ─────────────────────────────────────────────────────
  // Deserialization returns the object or throws on failure.

  mod.method("DeserializeCiphertextFromFile", [](const std::string& f, const BINARY& st) {
    CT obj;
    if (!lbcrypto::Serial::DeserializeFromFile(f, obj, st))
      throw std::runtime_error("DeserializeCiphertextFromFile: failed to open or parse " + f);
    return obj;
  });
  mod.method("DeserializeCiphertextFromFile", [](const std::string& f, const JSON& st) {
    CT obj;
    if (!lbcrypto::Serial::DeserializeFromFile(f, obj, st))
      throw std::runtime_error("DeserializeCiphertextFromFile: failed to open or parse " + f);
    return obj;
  });

  mod.method("DeserializeCryptoContextFromFile", [](const std::string& f, const BINARY& st) {
    CC obj;
    if (!lbcrypto::Serial::DeserializeFromFile(f, obj, st))
      throw std::runtime_error("DeserializeCryptoContextFromFile: failed to open or parse " + f);
    return obj;
  });
  mod.method("DeserializeCryptoContextFromFile", [](const std::string& f, const JSON& st) {
    CC obj;
    if (!lbcrypto::Serial::DeserializeFromFile(f, obj, st))
      throw std::runtime_error("DeserializeCryptoContextFromFile: failed to open or parse " + f);
    return obj;
  });

  mod.method("DeserializePublicKeyFromFile", [](const std::string& f, const BINARY& st) {
    PK obj;
    if (!lbcrypto::Serial::DeserializeFromFile(f, obj, st))
      throw std::runtime_error("DeserializePublicKeyFromFile: failed to open or parse " + f);
    return obj;
  });
  mod.method("DeserializePublicKeyFromFile", [](const std::string& f, const JSON& st) {
    PK obj;
    if (!lbcrypto::Serial::DeserializeFromFile(f, obj, st))
      throw std::runtime_error("DeserializePublicKeyFromFile: failed to open or parse " + f);
    return obj;
  });

  mod.method("DeserializePrivateKeyFromFile", [](const std::string& f, const BINARY& st) {
    SK obj;
    if (!lbcrypto::Serial::DeserializeFromFile(f, obj, st))
      throw std::runtime_error("DeserializePrivateKeyFromFile: failed to open or parse " + f);
    return obj;
  });
  mod.method("DeserializePrivateKeyFromFile", [](const std::string& f, const JSON& st) {
    SK obj;
    if (!lbcrypto::Serial::DeserializeFromFile(f, obj, st))
      throw std::runtime_error("DeserializePrivateKeyFromFile: failed to open or parse " + f);
    return obj;
  });

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

  mod.method("DeserializeCiphertextFromString", [](const std::string& json) {
    CT obj;
    lbcrypto::Serial::DeserializeFromString(obj, json);
    return obj;
  });
  mod.method("DeserializeCryptoContextFromString", [](const std::string& json) {
    CC obj;
    lbcrypto::Serial::DeserializeFromString(obj, json);
    return obj;
  });
  mod.method("DeserializePublicKeyFromString", [](const std::string& json) {
    PK obj;
    lbcrypto::Serial::DeserializeFromString(obj, json);
    return obj;
  });
  mod.method("DeserializePrivateKeyFromString", [](const std::string& json) {
    SK obj;
    lbcrypto::Serial::DeserializeFromString(obj, json);
    return obj;
  });

  // ── EvalMultKey serialization (file-based) ──────────────────────────────────

  mod.method("SerializeEvalMultKeyToFile", [](const std::string& f, const BINARY& st) {
    std::ofstream ofs(f, std::ios::out | std::ios::binary);
    if (!ofs.is_open()) return false;
    return CCImpl::SerializeEvalMultKey(ofs, st);
  });
  mod.method("SerializeEvalMultKeyToFile", [](const std::string& f, const JSON& st) {
    std::ofstream ofs(f, std::ios::out | std::ios::binary);
    if (!ofs.is_open()) return false;
    return CCImpl::SerializeEvalMultKey(ofs, st);
  });
  mod.method("SerializeEvalMultKeyToFile", [](const std::string& f, const BINARY& st, const CC& cc) {
    std::ofstream ofs(f, std::ios::out | std::ios::binary);
    if (!ofs.is_open()) return false;
    return CCImpl::SerializeEvalMultKey(ofs, st, cc);
  });
  mod.method("SerializeEvalMultKeyToFile", [](const std::string& f, const JSON& st, const CC& cc) {
    std::ofstream ofs(f, std::ios::out | std::ios::binary);
    if (!ofs.is_open()) return false;
    return CCImpl::SerializeEvalMultKey(ofs, st, cc);
  });

  mod.method("DeserializeEvalMultKeyFromFile", [](const std::string& f, const BINARY& st) {
    std::ifstream ifs(f, std::ios::in | std::ios::binary);
    if (!ifs.is_open()) return false;
    return CCImpl::DeserializeEvalMultKey(ifs, st);
  });
  mod.method("DeserializeEvalMultKeyFromFile", [](const std::string& f, const JSON& st) {
    std::ifstream ifs(f, std::ios::in | std::ios::binary);
    if (!ifs.is_open()) return false;
    return CCImpl::DeserializeEvalMultKey(ifs, st);
  });

  // ── EvalAutomorphismKey serialization (file-based) ──────────────────────────
  // This covers both EvalRotate and EvalSum keys, which share the same storage.

  mod.method("SerializeEvalAutomorphismKeyToFile", [](const std::string& f, const BINARY& st) {
    std::ofstream ofs(f, std::ios::out | std::ios::binary);
    if (!ofs.is_open()) return false;
    return CCImpl::SerializeEvalAutomorphismKey(ofs, st);
  });
  mod.method("SerializeEvalAutomorphismKeyToFile", [](const std::string& f, const JSON& st) {
    std::ofstream ofs(f, std::ios::out | std::ios::binary);
    if (!ofs.is_open()) return false;
    return CCImpl::SerializeEvalAutomorphismKey(ofs, st);
  });
  mod.method("SerializeEvalAutomorphismKeyToFile", [](const std::string& f, const BINARY& st, const CC& cc) {
    std::ofstream ofs(f, std::ios::out | std::ios::binary);
    if (!ofs.is_open()) return false;
    return CCImpl::SerializeEvalAutomorphismKey(ofs, st, cc);
  });
  mod.method("SerializeEvalAutomorphismKeyToFile", [](const std::string& f, const JSON& st, const CC& cc) {
    std::ofstream ofs(f, std::ios::out | std::ios::binary);
    if (!ofs.is_open()) return false;
    return CCImpl::SerializeEvalAutomorphismKey(ofs, st, cc);
  });

  mod.method("DeserializeEvalAutomorphismKeyFromFile", [](const std::string& f, const BINARY& st) {
    std::ifstream ifs(f, std::ios::in | std::ios::binary);
    if (!ifs.is_open()) return false;
    return CCImpl::DeserializeEvalAutomorphismKey(ifs, st);
  });
  mod.method("DeserializeEvalAutomorphismKeyFromFile", [](const std::string& f, const JSON& st) {
    std::ifstream ifs(f, std::ios::in | std::ios::binary);
    if (!ifs.is_open()) return false;
    return CCImpl::DeserializeEvalAutomorphismKey(ifs, st);
  });
}
