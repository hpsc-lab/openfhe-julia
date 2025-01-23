// Required until https://github.com/JuliaInterop/CxxWrap.jl/issues/455 has been solved
#ifdef __APPLE__
    #undef JLCXX_HAS_RANGES
#endif

#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_PublicKeyImpl(jlcxx::Module& mod) {
  // Source: <OpenFHE>/src/pke/include/key/publickey.h
  // Note: This file already contains all functions (except constructors) that are defined
  //       in OpenFHE. For feature completeness, one only needs to implement the currently
  //       commented functions.
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("PublicKeyImpl")
    .apply<lbcrypto::PublicKeyImpl<lbcrypto::DCRTPoly>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        // wrapped.method("GetPublicElements", &WrappedT::GetPublicElements);
        // wrapped.method("SetPublicElements", &WrappedT::SetPublicElements);
        // wrapped.method("SetPublicElementAtIndex", &WrappedT::SetPublicElementAtIndex);
        wrapped.method("operator==", &WrappedT::operator==);
        wrapped.method("operator!=", &WrappedT::operator!=);
        // wrapped.method("save", &WrappedT::save);
        // wrapped.method("load", &WrappedT::load);
        wrapped.method("SerializedObjectName", &WrappedT::SerializedObjectName);
        wrapped.module().method("PublicKeyImpl__SerializedVersion", &WrappedT::SerializedVersion);
      });
}
