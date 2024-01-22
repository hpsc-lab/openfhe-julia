#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

#include "openfhe_julia/jlcxx_parameters.h"

void wrap_CiphertextImpl(jlcxx::Module& mod) {
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("CiphertextImpl",
                                                     jlcxx::julia_base_type<lbcrypto::CryptoObject<lbcrypto::DCRTPoly>>())
    .apply<lbcrypto::CiphertextImpl<lbcrypto::DCRTPoly>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;

        wrapped.method("GetNoiseScaleDeg", &WrappedT::GetNoiseScaleDeg);
        wrapped.method("SetNoiseScaleDeg", &WrappedT::SetNoiseScaleDeg);
        wrapped.method("GetLevel", &WrappedT::GetLevel);
        wrapped.method("SetLevel", &WrappedT::SetLevel);
        wrapped.method("GetHopLevel", &WrappedT::GetHopLevel);
        wrapped.method("SetHopLevel", &WrappedT::SetHopLevel);
        wrapped.method("GetScalingFactor", &WrappedT::GetScalingFactor);
        wrapped.method("SetScalingFactor", &WrappedT::SetScalingFactor);
        wrapped.method("GetSlots", &WrappedT::GetSlots);
        wrapped.method("SetSlots", &WrappedT::SetSlots);
        wrapped.method("Clone", &WrappedT::Clone);
        wrapped.method("CloneZero", &WrappedT::CloneZero);
      });
}
