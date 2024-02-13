#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_Serializable(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::Serializable>("Serializable")
    .method("SerializedObjectName", &lbcrypto::Serializable::SerializedObjectName);
}
