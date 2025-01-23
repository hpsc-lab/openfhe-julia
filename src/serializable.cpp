#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

// Required until https://github.com/JuliaInterop/CxxWrap.jl/issues/455 has been solved
#ifdef __APPLE__
    #undef JLCXX_HAS_RANGES
#endif

void wrap_Serializable(jlcxx::Module& mod) {
  // Source: <OpenFHE>/src/core/include/utils/serializable.h
  // Note: This file wraps all functions (except constructors) that are defined in OpenFHE
  mod.add_type<lbcrypto::Serializable>("Serializable")
    .method("SerializedObjectName", &lbcrypto::Serializable::SerializedObjectName);
}
