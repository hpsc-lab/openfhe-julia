#include "openfhe_julia/jlcxx_modified.h"
#include "openfhe.h"

// Required until https://github.com/JuliaInterop/CxxWrap.jl/issues/455 has been solved
#ifdef __APPLE__
    #undef JLCXX_HAS_RANGES
#endif

#include "openfhe_julia/jlcxx_parameters.h"

void wrap_EncodingParamsImpl(jlcxx::Module& mod) {
  // Source: <OpenFHE>/src/pke/include/encoding/encodingparams.h
  // Note: This file wraps all functions (except constructors) that are defined in OpenFHE
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
    .method("SetBatchSize", &lbcrypto::EncodingParamsImpl::SetBatchSize)
    .method("operator==", &lbcrypto::EncodingParamsImpl::operator==)
    .method("operator!=", &lbcrypto::EncodingParamsImpl::operator!=);
}

