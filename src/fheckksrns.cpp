#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_FHECKKSRNS(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::FHECKKSRNS>("FHECKKSRNS")
    .apply<lbcrypto::FHECKKSRNS>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        wrapped.method("EvalBootstrapSetup", &lbcrypto::FHECKKSRNS::EvalBootstrapSetup);
        wrapped.method("EvalLinearTransformPrecompute", &lbcrypto::FHECKKSRNS::EvalLinearTransformPrecompute);
        wrapped.method("EvalLinearTransform", &lbcrypto::FHECKKSRNS::EvalLinearTransform);
        wrapped.module().method("GetBootstrapDepth", &lbcrypto::FHECKKSRNS::GetBootstrapDepth);
      });
}