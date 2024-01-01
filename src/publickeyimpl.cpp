#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_PublicKeyImpl(jlcxx::Module& mod) {
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("PublicKeyImpl")
    .apply<lbcrypto::PublicKeyImpl<lbcrypto::DCRTPoly>>([](auto wrapped) {});
}
