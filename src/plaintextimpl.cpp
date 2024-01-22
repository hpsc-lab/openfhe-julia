#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_PlaintextImpl(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::PlaintextImpl>("PlaintextImpl")
    .method("GetScalingFactor", &lbcrypto::PlaintextImpl::GetScalingFactor)
    .method("SetScalingFactor", &lbcrypto::PlaintextImpl::SetScalingFactor)
    .method("IsEncoded", &lbcrypto::PlaintextImpl::IsEncoded)
    .method("GetElementRingDimension", &lbcrypto::PlaintextImpl::GetElementRingDimension)
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
    .method("GetRealPackedValue", &lbcrypto::PlaintextImpl::GetRealPackedValue);
}
