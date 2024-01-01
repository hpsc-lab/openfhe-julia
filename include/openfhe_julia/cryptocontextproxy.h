#ifndef OPENFHE_JULIA_CRYPTOCONTEXTPROXY_H_
#define OPENFHE_JULIA_CRYPTOCONTEXTPROXY_H_

#include "jlcxx/jlcxx.hpp"

namespace openfhe_julia {
  // Note: Due to limitations of CxxWrap.jl, it is currently not possible to wrap template
  // types that are mutually dependent, which is the case here:
  // 1) `CryptoObject` defines a method `GetCryptoContext` that returns the
  //    `CryptoContextImpl`.
  // 2) `CiphertextImpl` inherits from `CryptoObject`, thus upon wrapping it with
  //    CxxWrap.jl, the return type `CryptoContextImpl` had the be wrapped before.
  // 3) `CryptoContextImpl` has methods that return `CiphertextImpl` object, thus
  //    `CiphertextImpl` needs to have been wrapped before.
  //
  // Since 2) and 3) are contradictory, we use the following non-template proxy class for an
  // additional level of indirection. With this, it is possible to first wrap the type
  // alone, and then add the methods later once the other template types have been wrapped.
  struct CryptoContextProxy {
    using CC = lbcrypto::CryptoContext<lbcrypto::DCRTPoly>;
    CC context;
    CryptoContextProxy(CC cc) : context(cc) {}
    CC GetCryptoContext() { return context; }
  };
}

inline
auto wrap_CryptoContextProxy_type(jlcxx::Module& mod) {
  return mod.add_type<openfhe_julia::CryptoContextProxy>("CryptoContextProxy");
}

template <typename T>
void wrap_CryptoContextProxy_methods(T& wrapped) {
  wrapped.method("GetCryptoContext", [](openfhe_julia::CryptoContextProxy& ccp) {
      return ccp.context;
    });
}

#endif // ifndef OPENFHE_JULIA_CRYPTOCONTEXTPROXY_H_
