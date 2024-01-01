#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_Params(jlcxx::Module& mod) {
  // Source: <OpenFHE>/src/pke/include/scheme/gen-cryptocontext-params.h
  mod.add_type<lbcrypto::Params>("Params")
    .method("SetMultiplicativeDepth", &lbcrypto::Params::SetMultiplicativeDepth)
    .method("SetScalingModSize", &lbcrypto::Params::SetScalingModSize)
    .method("SetBatchSize", &lbcrypto::Params::SetBatchSize)
    .method("SetSecretKeyDist", &lbcrypto::Params::SetSecretKeyDist)
    .method("SetSecurityLevel", &lbcrypto::Params::SetSecurityLevel)
    .method("SetRingDim", &lbcrypto::Params::SetRingDim)
    .method("SetScalingTechnique", &lbcrypto::Params::SetScalingTechnique)
    .method("SetFirstModSize", &lbcrypto::Params::SetFirstModSize)
    .method("SetNumLargeDigits", &lbcrypto::Params::SetNumLargeDigits)
    .method("SetKeySwitchTechnique", &lbcrypto::Params::SetKeySwitchTechnique);
}
