#include "jlcxx/jlcxx.hpp"

// Required until https://github.com/JuliaInterop/CxxWrap.jl/issues/455 has been solved
#ifdef __APPLE__
    #undef JLCXX_HAS_RANGES
#endif

#include "jlcxx/stl.hpp"
#include "openfhe.h"
#include "cryptocontext-ser.h"

#include "openfhe_julia/jlcxx_parameters.h"

using lbcrypto::DCRTPoly;
using lbcrypto::CryptoContext;

void wrap_CryptoContextFactory(jlcxx::Module& mod) {
    // TODO (GM): No idea which stl we actually need - commented out both because it does not work yet :(
    // jlcxx::stl::apply_vector<CryptoContext<DCRTPoly> >(mod);
    // jlcxx::stl::apply_set<CryptoContext<DCRTPoly> >(mod);

    using ContextVector = std::vector<CryptoContext<DCRTPoly>>;
    jlcxx::stl::apply_vector<CryptoContext<DCRTPoly>>(mod);

    mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("CryptoContextFactory")
        .apply<lbcrypto::CryptoContextFactory<DCRTPoly>>([](auto wrapped) {
                typedef typename decltype(wrapped)::type WrappedT;

                wrapped.module().method("ReleaseAllContexts", &WrappedT::ReleaseAllContexts);
                wrapped.module().method("GetContextCount", &WrappedT::GetContextCount);
                //wrapped.module().method("GetContext", &WrappedT::GetContext);
                wrapped.module().method("GetFullContextByDeserializedContext", &WrappedT::GetFullContextByDeserializedContext);

                wrapped.module().method("GetAllContexts", [](WrappedT& factory) {
                        return factory.GetAllContexts();
                });
        });
}
