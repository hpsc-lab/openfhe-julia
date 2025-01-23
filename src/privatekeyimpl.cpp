#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_PrivateKeyImpl(jlcxx::Module& mod) {
  // Source: <OpenFHE>/src/pke/include/key/privatekey.h
  // Note: This file already contains all functions (except constructors) that are defined
  //       in OpenFHE. For feature completeness, one only needs to implement the currently
  //       commented functions.
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("PrivateKeyImpl")
    .apply<lbcrypto::PrivateKeyImpl<lbcrypto::DCRTPoly>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        // wrapped.method("GetPrivateElement", &WrappedT::GetPrivateElement);
        // wrapped.method("SetPrivateElement", &WrappedT::SetPrivateElement);
        wrapped.method("operator==", &WrappedT::operator==);
        wrapped.method("operator!=", &WrappedT::operator!=);
        // wrapped.method("save", &WrappedT::save);
        // wrapped.method("load", &WrappedT::load);
        wrapped.method("SerializedObjectName", &WrappedT::SerializedObjectName);
        wrapped.module().method("PrivateKeyImpl__SerializedVersion", &WrappedT::SerializedVersion);
      });
}
