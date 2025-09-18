#include "jlcxx/jlcxx.hpp"

// Required until https://github.com/JuliaInterop/CxxWrap.jl/issues/455 has been solved
#ifdef __APPLE__
    #undef JLCXX_HAS_RANGES
#endif

#include "openfhe.h"
#include "openfhe_julia/jlcxx_parameters.h"

void wrap_CryptoContextFactory(jlcxx::Module& mod) {
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("CryptoContextFactory")
    .apply<lbcrypto::CryptoContextFactory<lbcrypto::DCRTPoly>>([](auto wrapped) {
    typedef typename decltype(wrapped)::type WrappedT;

    wrapped.module().method("ReleaseAllContexts", &WrappedT::ReleaseAllContexts);
    wrapped.module().method("GetContextCount", &WrappedT::GetContextCount);
    //wrapped.module().method("GetContext", &WrappedT::GetContext);
    wrapped.module().method("GetFullContextByDeserializedContext", &WrappedT::GetFullContextByDeserializedContext);    
    wrapped.module().method("GetAllContexts", &WrappedT::GetAllContexts);
  });
}
