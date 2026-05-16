#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"
#include "cryptocontext-ser.h"

void wrap_Serial(jlcxx::Module& mod) {
  // Source: <OpenFHE>/src/core/include/utils/serial.h
  using DCRTPoly    = lbcrypto::DCRTPoly;
  using CC          = lbcrypto::CryptoContext<DCRTPoly>;
  using CT          = lbcrypto::Ciphertext<DCRTPoly>;
  using PK          = lbcrypto::PublicKey<DCRTPoly>;
  using SK          = lbcrypto::PrivateKey<DCRTPoly>;

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
}
