#include "openfhe_julia/jlcxx_modified.h"
#include "openfhe.h"

void wrap_Serializable(jlcxx::Module& mod) {
  // Source: <OpenFHE>/src/core/include/utils/serializable.h
  // Note: This file wraps all functions (except constructors) that are defined in OpenFHE
  mod.add_type<lbcrypto::Serializable>("Serializable")
    .method("SerializedObjectName", &lbcrypto::Serializable::SerializedObjectName);
}
