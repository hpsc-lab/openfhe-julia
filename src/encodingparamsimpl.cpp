#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

#include "openfhe_julia/jlcxx_parameters.h"

void wrap_EncodingParamsImpl(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::EncodingParamsImpl>("EncodingParamsImpl",
      jlcxx::julia_base_type<lbcrypto::Serializable>())
    .method("GetPlaintextModulus", &lbcrypto::EncodingParamsImpl::GetPlaintextModulus)
    .method("SetPlaintextModulus", &lbcrypto::EncodingParamsImpl::SetPlaintextModulus)
    .method("GetPlaintextRootOfUnity", &lbcrypto::EncodingParamsImpl::GetPlaintextRootOfUnity)
    .method("SetPlaintextRootOfUnity", &lbcrypto::EncodingParamsImpl::SetPlaintextRootOfUnity)
    .method("GetPlaintextBigModulus", &lbcrypto::EncodingParamsImpl::GetPlaintextBigModulus)
    .method("SetPlaintextBigModulus", &lbcrypto::EncodingParamsImpl::SetPlaintextBigModulus)
    .method("GetPlaintextBigRootOfUnity", &lbcrypto::EncodingParamsImpl::GetPlaintextBigRootOfUnity)
    .method("SetPlaintextBigRootOfUnity", &lbcrypto::EncodingParamsImpl::SetPlaintextBigRootOfUnity)
    .method("GetPlaintextGenerator", &lbcrypto::EncodingParamsImpl::GetPlaintextGenerator)
    .method("SetPlaintextGenerator", &lbcrypto::EncodingParamsImpl::SetPlaintextGenerator)
    .method("GetBatchSize", &lbcrypto::EncodingParamsImpl::GetBatchSize)
    .method("SetBatchSize", &lbcrypto::EncodingParamsImpl::SetBatchSize);
}

