#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_FHECKKSRNS(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::FHECKKSRNS>("FHECKKSRNS")
  .method("EvalBootstrapSetup", &lbcrypto::FHECKKSRNS::EvalBootstrapSetup)
  .method("EvalLinearTransformPrecompute", 
      static_cast<std::vector<lbcrypto::ConstPlaintext> 
                  (lbcrypto::FHECKKSRNS::*)(const lbcrypto::CryptoContextImpl<lbcrypto::DCRTPoly>&,
                  const std::vector<std::vector<std::complex<double>>>&,
                  double scale, uint32_t) const>(&lbcrypto::FHECKKSRNS::EvalLinearTransformPrecompute))
  .method("EvalLinearTransformPrecompute", 
      static_cast<std::vector<lbcrypto::ConstPlaintext> 
                  (lbcrypto::FHECKKSRNS::*)(const lbcrypto::CryptoContextImpl<lbcrypto::DCRTPoly>&,
                  const std::vector<std::vector<std::complex<double>>>&,
                  const std::vector<std::vector<std::complex<double>>>&,
                  uint32_t, double scale, uint32_t) const>
                  (&lbcrypto::FHECKKSRNS::EvalLinearTransformPrecompute))
  .method("EvalLinearTransform", &lbcrypto::FHECKKSRNS::EvalLinearTransform)
  .module().method("GetBootstrapDepth",
      static_cast<uint32_t
                  (*)(const std::vector<uint32_t>&,
                  lbcrypto::SecretKeyDist)>(&lbcrypto::FHECKKSRNS::GetBootstrapDepth));
}