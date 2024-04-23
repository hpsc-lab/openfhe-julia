#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_FHECKKSRNS(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::FHECKKSRNS>("FHECKKSRNS")
    .method("EvalBootstrapSetup", &lbcrypto::FHECKKSRNS::EvalBootstrapSetup)
    .method("EvalLinearTransformPrecompute", &lbcrypto::FHECKKSRNS::EvalLinearTransformPrecompute)
    .method("EvalLinearTransform", &lbcrypto::FHECKKSRNS::EvalLinearTransform)
    .module().method("GetBootstrapDepth", &lbcrypto::FHECKKSRNS::GetBootstrapDepth);
}