#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_Params(jlcxx::Module& mod) {
  // Source: <OpenFHE>/src/pke/include/scheme/gen-cryptocontext-params.h
  // Note: This file already contains all functions (except constructors) that are defined
  //       in OpenFHE. For feature completeness, one only needs to implement the currently
  //       commented functions.
  mod.add_type<lbcrypto::Params>("Params")
    // .method("GetScheme", &lbcrypto::Params::GetScheme) // missing types
    .method("GetPlaintextModulus", &lbcrypto::Params::GetPlaintextModulus)
    .method("GetDigitSize", &lbcrypto::Params::GetDigitSize)
    .method("GetStandardDeviation", &lbcrypto::Params::GetStandardDeviation)
    .method("GetSecretKeyDist", &lbcrypto::Params::GetSecretKeyDist)
    .method("GetMaxRelinSkDeg", &lbcrypto::Params::GetMaxRelinSkDeg)
    // .method("GetPREMode", &lbcrypto::Params::GetPREMode) // missing types
    // .method("GetMultipartyMode", &lbcrypto::Params::GetMultipartyMode) // missing types
    // .method("GetExecutionMode", &lbcrypto::Params::GetExecutionMode // missing types)
    // .method("GetDecryptionNoiseMode", &lbcrypto::Params::GetDecryptionNoiseMode) // missing types
    .method("GetNoiseEstimate", &lbcrypto::Params::GetNoiseEstimate)
    .method("GetDesiredPrecision", &lbcrypto::Params::GetDesiredPrecision)
    .method("GetStatisticalSecurity", &lbcrypto::Params::GetStatisticalSecurity)
    .method("GetNumAdversarialQueries", &lbcrypto::Params::GetNumAdversarialQueries)
    .method("GetThresholdNumOfParties", &lbcrypto::Params::GetThresholdNumOfParties)
    .method("GetKeySwitchTechnique", &lbcrypto::Params::GetKeySwitchTechnique)
    .method("GetScalingTechnique", &lbcrypto::Params::GetScalingTechnique)
    .method("GetBatchSize", &lbcrypto::Params::GetBatchSize)
    .method("GetFirstModSize", &lbcrypto::Params::GetFirstModSize)
    .method("GetNumLargeDigits", &lbcrypto::Params::GetNumLargeDigits)
    .method("GetMultiplicativeDepth", &lbcrypto::Params::GetMultiplicativeDepth)
    .method("GetScalingModSize", &lbcrypto::Params::GetScalingModSize)
    .method("GetSecurityLevel", &lbcrypto::Params::GetSecurityLevel)
    .method("GetRingDim", &lbcrypto::Params::GetRingDim)
    .method("GetEvalAddCount", &lbcrypto::Params::GetEvalAddCount)
    .method("GetKeySwitchCount", &lbcrypto::Params::GetKeySwitchCount)
    // .method("GetEncryptionTechnique", &lbcrypto::Params::GetEncryptionTechnique) // missing types
    // .method("GetMultiplicationTechnique", &lbcrypto::Params::GetMultiplicationTechnique) // missing types
    .method("GetMultiHopModSize", &lbcrypto::Params::GetMultiHopModSize)
    // .method("GetInteractiveBootCompressionLevel", &lbcrypto::Params::GetInteractiveBootCompressionLevel) // missing types

    // .method("SetScheme", &lbcrypto::Params::SetScheme) // missing types
    .method("SetPlaintextModulus", &lbcrypto::Params::SetPlaintextModulus)
    .method("SetDigitSize", &lbcrypto::Params::SetDigitSize)
    .method("SetStandardDeviation", &lbcrypto::Params::SetStandardDeviation)
    .method("SetSecretKeyDist", &lbcrypto::Params::SetSecretKeyDist)
    .method("SetMaxRelinSkDeg", &lbcrypto::Params::SetMaxRelinSkDeg)
    // .method("SetPREMode", &lbcrypto::Params::SetPREMode) // missing types
    // .method("SetMultipartyMode", &lbcrypto::Params::SetMultipartyMode) // missing types
    // .method("SetExecutionMode", &lbcrypto::Params::SetExecutionMode // missing types)
    // .method("SetDecryptionNoiseMode", &lbcrypto::Params::SetDecryptionNoiseMode) // missing types
    .method("SetNoiseEstimate", &lbcrypto::Params::SetNoiseEstimate)
    .method("SetDesiredPrecision", &lbcrypto::Params::SetDesiredPrecision)
    .method("SetStatisticalSecurity", &lbcrypto::Params::SetStatisticalSecurity)
    .method("SetNumAdversarialQueries", &lbcrypto::Params::SetNumAdversarialQueries)
    .method("SetThresholdNumOfParties", &lbcrypto::Params::SetThresholdNumOfParties)
    .method("SetKeySwitchTechnique", &lbcrypto::Params::SetKeySwitchTechnique)
    .method("SetScalingTechnique", &lbcrypto::Params::SetScalingTechnique)
    .method("SetBatchSize", &lbcrypto::Params::SetBatchSize)
    .method("SetFirstModSize", &lbcrypto::Params::SetFirstModSize)
    .method("SetNumLargeDigits", &lbcrypto::Params::SetNumLargeDigits)
    .method("SetMultiplicativeDepth", &lbcrypto::Params::SetMultiplicativeDepth)
    .method("SetScalingModSize", &lbcrypto::Params::SetScalingModSize)
    .method("SetSecurityLevel", &lbcrypto::Params::SetSecurityLevel)
    .method("SetRingDim", &lbcrypto::Params::SetRingDim)
    .method("SetEvalAddCount", &lbcrypto::Params::SetEvalAddCount)
    .method("SetKeySwitchCount", &lbcrypto::Params::SetKeySwitchCount)
    // .method("SetEncryptionTechnique", &lbcrypto::Params::SetEncryptionTechnique) // missing types
    // .method("SetMultiplicationTechnique", &lbcrypto::Params::SetMultiplicationTechnique) // missing types
    .method("SetMultiHopModSize", &lbcrypto::Params::SetMultiHopModSize);
    // .method("SetInteractiveBootCompressionLevel", &lbcrypto::Params::SetInteractiveBootCompressionLevel) // missing types
}
