#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_FHECKKSRNS(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::FHECKKSRNS>("FHECKKSRNS")
  .method("EvalBootstrapSetup", &lbcrypto::FHECKKSRNS::EvalBootstrapSetup)
  .method("EvalLinearTransformPrecompute", 
      static_cast<std::vector<lbcrypto::ConstPlaintext>
                  (lbcrypto::FHECKKSRNS::*)(const lbcrypto::CryptoContextImpl<lbcrypto::DCRTPoly>&,
                      const std::vector<std::vector<std::complex<double>>>&,
                      double, uint32_t)>(&lbcrypto::FHECKKSRNS::EvalLinearTransformPrecompute))
  .method("EvalLinearTransform", &lbcrypto::FHECKKSRNS::EvalLinearTransform)
  .module().method("GetBootstrapDepth",
      static_cast<uint32_t
                  (lbcrypto::FHECKKSRNS::*)(const std::vector<uint32_t>&,
                  lbcrypto::SecretKeyDist)>(&lbcrypto::FHECKKSRNS::GetBootstrapDepth));
}