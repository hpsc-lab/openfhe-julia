#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_PlaintextImpl(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::PlaintextImpl>("PlaintextImpl")
    .method("SetLength", &lbcrypto::PlaintextImpl::SetLength)
    .method("GetLogPrecision", &lbcrypto::PlaintextImpl::GetLogPrecision)
    .method("GetRealPackedValue", &lbcrypto::PlaintextImpl::GetRealPackedValue);
}
