#include "jlcxx/jlcxx.hpp"

// Workaround: disabled ranges usage in jlcxx because of an ambiguity with libstdc++.
// Not disabling will result in an error when loading "jlcxx/stl.hpp",
// the issue: https://github.com/hpsc-lab/openfhe-julia/pull/101#discussion_r2414278271
#undef JLCXX_HAS_RANGES

#include "jlcxx/stl.hpp"
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
