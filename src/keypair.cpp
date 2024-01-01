#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_KeyPair(jlcxx::Module& mod) {
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("KeyPair")
    .apply<lbcrypto::KeyPair<lbcrypto::DCRTPoly>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        // Use `module()` to add free function
        wrapped.module().method("private_key", [](WrappedT& w) { return w.secretKey; });
        wrapped.module().method("public_key", [](WrappedT& w) { return w.publicKey; });
      });
}
