#include "openfhe_julia/jlcxx_modified.h"
#include "openfhe.h"

#include "openfhe_julia/cryptocontextproxy.h"

void wrap_CryptoObject(jlcxx::Module& mod) {
  // Source: <OpenFHE>/src/pke/include/cryptoobject.h
  // Note: This file already contains all functions (except constructors) that are defined
  //       in OpenFHE. For feature completeness, one only needs to implement the currently
  //       commented functions.
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("CryptoObject")
    .apply<lbcrypto::CryptoObject<lbcrypto::DCRTPoly>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        wrapped.method("operator==", &WrappedT::operator==);
        // Necessary since `CryptoContext` is not yet defined here
        wrapped.method("GetCryptoContextProxy", [](WrappedT& w) {
            return openfhe_julia::CryptoContextProxy(w.GetCryptoContext());
          });
        // wrapped.method("GetCryptoParameters", &WrappedT::GetCryptoParameters);
        wrapped.method("GetEncodingParameters", &WrappedT::GetEncodingParameters);
        wrapped.method("GetKeyTag", &WrappedT::GetKeyTag);
        wrapped.method("SetKeyTag", &WrappedT::SetKeyTag);
        // wrapped.method("save", &WrappedT::save);
        // wrapped.method("load", &WrappedT::load);
        wrapped.method("SerializedObjectName", &WrappedT::SerializedObjectName);
        wrapped.module().method("CryptoObject__SerializedVersion", &WrappedT::SerializedVersion);
      });
}
