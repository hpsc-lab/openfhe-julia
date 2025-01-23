#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

// Required until https://github.com/JuliaInterop/CxxWrap.jl/issues/455 has been solved
#ifdef __APPLE__
    #undef JLCXX_HAS_RANGES
#endif

void wrap_PlaintextImpl(jlcxx::Module& mod) {
  // Source: <OpenFHE>/src/pke/include/encoding/plaintext.h
  // Note: This file already contains all functions (except constructors) that are defined
  //       in OpenFHE. For feature completeness, one only needs to implement the currently
  //       commented functions.
  mod.add_type<lbcrypto::PlaintextImpl>("PlaintextImpl")
    .method("GetEncodingType", &lbcrypto::PlaintextImpl::GetEncodingType)
    .method("GetScalingFactor", &lbcrypto::PlaintextImpl::GetScalingFactor)
    .method("SetScalingFactor", &lbcrypto::PlaintextImpl::SetScalingFactor)
    .method("GetScalingFactorInt", &lbcrypto::PlaintextImpl::GetScalingFactorInt)
    .method("SetScalingFactorInt", &lbcrypto::PlaintextImpl::SetScalingFactorInt)
    .method("GetSchemeID", &lbcrypto::PlaintextImpl::GetSchemeID)
    .method("IsEncoded", &lbcrypto::PlaintextImpl::IsEncoded)
    .method("GetEncodingParams", &lbcrypto::PlaintextImpl::GetEncodingParams)
    .method("Encode", &lbcrypto::PlaintextImpl::Encode)
    .method("Decode", &lbcrypto::PlaintextImpl::Decode)
    .method("LowBound", &lbcrypto::PlaintextImpl::LowBound)
    .method("HighBound", &lbcrypto::PlaintextImpl::HighBound)
    // .method("SetFormat", &lbcrypto::PlaintextImpl::SetFormat)
    // .method("GetElement", &lbcrypto::PlaintextImpl::GetElement)
    .method("GetElementRingDimension", &lbcrypto::PlaintextImpl::GetElementRingDimension)
    .method("GetElementModulus", &lbcrypto::PlaintextImpl::GetElementModulus)
    .method("GetLength", &lbcrypto::PlaintextImpl::GetLength)
    .method("SetLength", &lbcrypto::PlaintextImpl::SetLength)
    .method("GetNoiseScaleDeg", &lbcrypto::PlaintextImpl::GetNoiseScaleDeg)
    .method("SetNoiseScaleDeg", &lbcrypto::PlaintextImpl::SetNoiseScaleDeg)
    .method("GetLevel", &lbcrypto::PlaintextImpl::GetLevel)
    .method("SetLevel", &lbcrypto::PlaintextImpl::SetLevel)
    .method("GetSlots", &lbcrypto::PlaintextImpl::GetSlots)
    .method("SetSlots", &lbcrypto::PlaintextImpl::SetSlots)
    .method("GetLogError", &lbcrypto::PlaintextImpl::GetLogError)
    .method("GetLogPrecision", &lbcrypto::PlaintextImpl::GetLogPrecision)
    .method("GetStringValue", &lbcrypto::PlaintextImpl::GetStringValue)
    .method("GetCoefPackedValue", &lbcrypto::PlaintextImpl::GetCoefPackedValue)
    .method("GetPackedValue", &lbcrypto::PlaintextImpl::GetPackedValue)
    // .method("GetCKKSPackedValue", &lbcrypto::PlaintextImpl::GetCKKSPackedValue)
    .method("GetRealPackedValue", &lbcrypto::PlaintextImpl::GetRealPackedValue)
    // .method("SetStringValue", &lbcrypto::PlaintextImpl::SetStringValue)
    // .method("SetIntVectorValue", &lbcrypto::PlaintextImpl::SetIntVectorValue)
    .method("CompareTo", &lbcrypto::PlaintextImpl::CompareTo)
    .method("operator==", &lbcrypto::PlaintextImpl::operator==)
    .method("operator!=", &lbcrypto::PlaintextImpl::operator!=);
    // .method("PrintValue", &lbcrypto::PlaintextImpl::PrintValue);
}
