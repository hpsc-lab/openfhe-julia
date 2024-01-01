#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

#include "openfhe_julia/jlcxx_parameters.h"

void wrap_CiphertextImpl(jlcxx::Module& mod) {
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("CiphertextImpl",
                                                     jlcxx::julia_base_type<lbcrypto::CryptoObject<lbcrypto::DCRTPoly>>())
    .apply<lbcrypto::CiphertextImpl<lbcrypto::DCRTPoly>>([](auto wrapped) {});
}
