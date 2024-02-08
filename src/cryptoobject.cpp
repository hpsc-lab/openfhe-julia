#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

#include "openfhe_julia/cryptocontextproxy.h"
#include "openfhe_julia/jlcxx_parameters.h"

void wrap_CryptoObject(jlcxx::Module& mod) {
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("CryptoObject")
    .apply<lbcrypto::CryptoObject<lbcrypto::DCRTPoly>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        wrapped.method("GetCryptoContextProxy", [](WrappedT& w) {
            return openfhe_julia::CryptoContextProxy(w.GetCryptoContext());
          });
	wrapped.method("GetEncodingParameters", &WrappedT::GetEncodingParameters);
      });
}
