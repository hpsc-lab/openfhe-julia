#include "openfhe_julia/jlcxx_modified.h"
#include "openfhe.h"

void wrap_KeyPair(jlcxx::Module& mod) {
  // Source: <OpenFHE>/src/pke/include/key/keypair.h
  // Note: This file wraps all functions (except constructors) that are defined in OpenFHE
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("KeyPair")
    .apply<lbcrypto::KeyPair<lbcrypto::DCRTPoly>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        wrapped.method("good", &WrappedT::good);

        // Use `module()` to add free function
        wrapped.module().method("private_key", [](WrappedT& w) { return w.secretKey; });
        wrapped.module().method("public_key", [](WrappedT& w) { return w.publicKey; });
      });
}
