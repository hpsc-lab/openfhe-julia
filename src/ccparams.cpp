#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

#include "openfhe_julia/jlcxx_parameters.h"

void wrap_CCParams(jlcxx::Module& mod) {
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("CCParams", jlcxx::julia_base_type<lbcrypto::Params>())
    .apply<lbcrypto::CCParams<lbcrypto::CryptoContextCKKSRNS>>([](auto wrapped) {});
}
