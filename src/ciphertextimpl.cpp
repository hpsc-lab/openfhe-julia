#include "openfhe_julia/jlcxx_modified.h"
#include "openfhe.h"

// Required until https://github.com/JuliaInterop/CxxWrap.jl/issues/455 has been solved
#ifdef __APPLE__
    #undef JLCXX_HAS_RANGES
#endif

#include "openfhe_julia/jlcxx_parameters.h"

void wrap_CiphertextImpl(jlcxx::Module& mod) {
  // Source: <OpenFHE>/src/pke/include/ciphertext.h
  // Note: This file already contains all functions (except constructors) that are defined
  //       in OpenFHE. For feature completeness, one only needs to implement the currently
  //       commented functions.
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("CiphertextImpl",
      jlcxx::julia_base_type<lbcrypto::CryptoObject<lbcrypto::DCRTPoly>>())
    .apply<lbcrypto::CiphertextImpl<lbcrypto::DCRTPoly>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;

        wrapped.method("GetEncodingType", &WrappedT::GetEncodingType);
        wrapped.method("SetEncodingType", &WrappedT::SetEncodingType);
        // wrapped.method("GetElement", &WrappedT::GetElement);
        // wrapped.method("GetElements", &WrappedT::GetElements);
        // wrapped.method("SetElement", &WrappedT::SetElement);
        // wrapped.method("SetElements", &WrappedT::SetElements);
        wrapped.method("GetNoiseScaleDeg", &WrappedT::GetNoiseScaleDeg);
        wrapped.method("SetNoiseScaleDeg", &WrappedT::SetNoiseScaleDeg);
        wrapped.method("GetLevel", &WrappedT::GetLevel);
        wrapped.method("SetLevel", &WrappedT::SetLevel);
        wrapped.method("GetHopLevel", &WrappedT::GetHopLevel);
        wrapped.method("SetHopLevel", &WrappedT::SetHopLevel);
        wrapped.method("GetScalingFactor", &WrappedT::GetScalingFactor);
        wrapped.method("SetScalingFactor", &WrappedT::SetScalingFactor);
        wrapped.method("GetScalingFactorInt", &WrappedT::GetScalingFactorInt);
        wrapped.method("SetScalingFactorInt", &WrappedT::SetScalingFactorInt);
        wrapped.method("GetSlots", &WrappedT::GetSlots);
        wrapped.method("SetSlots", &WrappedT::SetSlots);
        // wrapped.method("GetMetaDataMap", &WrappedT::GetMetaDataMap);
        // wrapped.method("SetMetaDataMap", &WrappedT::SetMetaDataMap);
        // wrapped.method("FindMetadataByKey", &WrappedT::FindMetadataByKey);
        // wrapped.method("MetadataFound", &WrappedT::MetadataFound);
        // wrapped.method("GetMetadata", &WrappedT::GetMetadata);
        // wrapped.method("GetMetadataByKey", &WrappedT::GetMetadataByKey);
        // wrapped.method("SetMetadataByKey", &WrappedT::SetMetadataByKey);
        wrapped.method("Clone", &WrappedT::Clone);
        wrapped.method("CloneZero", &WrappedT::CloneZero);
        // wrapped.method("save", &WrappedT::save);
        // wrapped.method("load", &WrappedT::load);
        wrapped.method("SerializedObjectName", &WrappedT::SerializedObjectName);
        wrapped.module().method("CiphertextImpl__SerializedVersion", &WrappedT::SerializedVersion);
        wrapped.method("operator==", &WrappedT::operator==);
        wrapped.method("operator!=", &WrappedT::operator!=);
      });
}
