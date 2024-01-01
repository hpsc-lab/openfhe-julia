#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_PrivateKeyImpl(jlcxx::Module& mod) {
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("PrivateKeyImpl")
    .apply<lbcrypto::PrivateKeyImpl<lbcrypto::DCRTPoly>>([](auto wrapped) {});
}
