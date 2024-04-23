#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_FHECKKSRNS(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::FHECKKSRNS>("FHECKKSRNS")
  .method("EvalBootstrapSetup", &lbcrypto::FHECKKSRNS::EvalBootstrapSetup)
  .method("EvalLinearTransform", &lbcrypto::FHECKKSRNS::EvalLinearTransform)
  .module().method("GetBootstrapDepth",
      static_cast<uint32_t
                  (*)(const std::vector<uint32_t>&,
                  lbcrypto::SecretKeyDist)>(&lbcrypto::FHECKKSRNS::GetBootstrapDepth));
}