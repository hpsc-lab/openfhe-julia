// C++ includes
#include <string>

// CxxWrap includes
#include "jlcxx/jlcxx.hpp"

// OpenFHE includes
#include "openfhe.h"


namespace jlcxx
{
  template<> struct IsMirroredType<lbcrypto::CryptoContextCKKSRNS> : std::false_type { };
  template<> struct SuperType<lbcrypto::CCParams<lbcrypto::CryptoContextCKKSRNS>> { typedef lbcrypto::Params type; };
  template<> struct SuperType<lbcrypto::CryptoContextImpl<lbcrypto::DCRTPoly>> { typedef lbcrypto::Serializable type; };
}


void wrap_PKESchemeFeature(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::PKESchemeFeature>("PKESchemeFeature", jlcxx::julia_type("CppEnum"));
  mod.set_const("PKE", lbcrypto::PKE);
  mod.set_const("KEYSWITCH", lbcrypto::KEYSWITCH);
  mod.set_const("PRE", lbcrypto::PRE);
  mod.set_const("LEVELEDSHE", lbcrypto::LEVELEDSHE);
  mod.set_const("ADVANCEDSHE", lbcrypto::ADVANCEDSHE);
  mod.set_const("MULTIPARTY", lbcrypto::MULTIPARTY);
  mod.set_const("FHE", lbcrypto::FHE);
  mod.set_const("SCHEMESWITCH", lbcrypto::SCHEMESWITCH);
}

void wrap_ScalingTechnique(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::ScalingTechnique>("ScalingTechnique", jlcxx::julia_type("CppEnum"));
  mod.set_const("FIXEDMANUAL", lbcrypto::FIXEDMANUAL);
  mod.set_const("FIXEDAUTO", lbcrypto::FIXEDAUTO);
  mod.set_const("FLEXIBLEAUTO", lbcrypto::FLEXIBLEAUTO);
  mod.set_const("FLEXIBLEAUTOEXT", lbcrypto::FLEXIBLEAUTOEXT);
  mod.set_const("NORESCALE", lbcrypto::NORESCALE);
  mod.set_const("INVALID_RS_TECHNIQUE", lbcrypto::INVALID_RS_TECHNIQUE);
}

void wrap_SecretKeyDist(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::SecretKeyDist>("SecretKeyDist", jlcxx::julia_type("CppEnum"));
  mod.set_const("GAUSSIAN", lbcrypto::GAUSSIAN);
  mod.set_const("UNIFORM_TERNARY", lbcrypto::UNIFORM_TERNARY);
  mod.set_const("SPARSE_TERNARY", lbcrypto::SPARSE_TERNARY);
}

void wrap_DistributionType(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::DistributionType>("DistributionType", jlcxx::julia_type("CppEnum"));
  mod.set_const("HEStd_uniform", lbcrypto::HEStd_uniform);
  mod.set_const("HEStd_error", lbcrypto::HEStd_error);
  mod.set_const("HEStd_ternary", lbcrypto::HEStd_ternary);
}

void wrap_SecurityLevel(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::SecurityLevel>("SecurityLevel", jlcxx::julia_type("CppEnum"));
  mod.set_const("HEStd_128_classic", lbcrypto::HEStd_128_classic);
  mod.set_const("HEStd_192_classic", lbcrypto::HEStd_192_classic);
  mod.set_const("HEStd_256_classic", lbcrypto::HEStd_256_classic);
  mod.set_const("HEStd_128_quantum", lbcrypto::HEStd_128_quantum);
  mod.set_const("HEStd_192_quantum", lbcrypto::HEStd_192_quantum);
  mod.set_const("HEStd_256_quantum", lbcrypto::HEStd_256_quantum);
  mod.set_const("HEStd_NotSet", lbcrypto::HEStd_NotSet);
}

void wrap_CryptoContextCKKSRNS(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::CryptoContextCKKSRNS>("CryptoContextCKKSRNS");
}

void wrap_FHECKKSRNS(jlcxx::Module& mod) {
  mod.method("GetBootstrapDepth",
      static_cast<uint32_t
                  (*)(const std::vector<uint32_t>&,
                  lbcrypto::SecretKeyDist)>(&lbcrypto::FHECKKSRNS::GetBootstrapDepth));
}

void wrap_Params(jlcxx::Module& mod) {
  // Source: <OpenFHE>/src/pke/include/scheme/gen-cryptocontext-params.h
  mod.add_type<lbcrypto::Params>("Params")
    .method("SetMultiplicativeDepth", &lbcrypto::Params::SetMultiplicativeDepth)
    .method("SetScalingModSize", &lbcrypto::Params::SetScalingModSize)
    .method("SetBatchSize", &lbcrypto::Params::SetBatchSize)
    .method("SetSecretKeyDist", &lbcrypto::Params::SetSecretKeyDist)
    .method("SetSecurityLevel", &lbcrypto::Params::SetSecurityLevel)
    .method("SetRingDim", &lbcrypto::Params::SetRingDim)
    .method("SetScalingTechnique", &lbcrypto::Params::SetScalingTechnique)
    .method("SetFirstModSize", &lbcrypto::Params::SetFirstModSize)
    .method("SetMultiplicativeDepth", &lbcrypto::Params::SetMultiplicativeDepth)
    .method("SetNumLargeDigits", &lbcrypto::Params::SetNumLargeDigits)
    .method("SetKeySwitchTechnique", &lbcrypto::Params::SetKeySwitchTechnique);
}

void wrap_CCParams(jlcxx::Module& mod) {
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("CCParams", jlcxx::julia_base_type<lbcrypto::Params>())
    .apply<lbcrypto::CCParams<lbcrypto::CryptoContextCKKSRNS>>([](auto wrapped) {});
}

void wrap_Serializable(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::Serializable>("Serializable");
}

void wrap_DCRTPoly(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::DCRTPoly>("DCRTPoly");
}

void wrap_PrivateKeyImpl(jlcxx::Module& mod) {
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("PrivateKeyImpl")
    .apply<lbcrypto::PrivateKeyImpl<lbcrypto::DCRTPoly>>([](auto wrapped) {});
}

void wrap_PublicKeyImpl(jlcxx::Module& mod) {
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("PublicKeyImpl")
    .apply<lbcrypto::PublicKeyImpl<lbcrypto::DCRTPoly>>([](auto wrapped) {});
}

void wrap_KeyPair(jlcxx::Module& mod) {
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("KeyPair")
    .apply<lbcrypto::KeyPair<lbcrypto::DCRTPoly>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        // Use `module()` to add free function
        wrapped.module().method("private_key", [](WrappedT& w) { return w.secretKey; });
        wrapped.module().method("public_key", [](WrappedT& w) { return w.publicKey; });
      });
}

void wrap_PlaintextImpl(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::PlaintextImpl>("PlaintextImpl")
    .method("SetLength", &lbcrypto::PlaintextImpl::SetLength)
    .method("GetLogPrecision", &lbcrypto::PlaintextImpl::GetLogPrecision)
    .method("GetRealPackedValue", &lbcrypto::PlaintextImpl::GetRealPackedValue);
}

void wrap_Plaintext(jlcxx::Module& mod) {
  // `Plaintext`s need to be creatable
  mod.method("Plaintext", []() { return lbcrypto::Plaintext(); });
  // Helper function for getting the text representation
  mod.method("_to_string_plaintext", [](lbcrypto::Plaintext& pt) {
      std::ostringstream stream;
      pt->PrintValue(stream);
      return stream.str();
    });
}

void wrap_CiphertextImpl(jlcxx::Module& mod) {
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("CiphertextImpl")
    .apply<lbcrypto::CiphertextImpl<lbcrypto::DCRTPoly>>([](auto wrapped) {});
}

void wrap_DecryptResult(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::DecryptResult>("DecryptResult");
}

void wrap_CryptoContextImpl(jlcxx::Module& mod) {
  // Source: <OpenFHE>/src/pke/include/cryptocontext.h
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("CryptoContextImpl", jlcxx::julia_base_type<lbcrypto::Serializable>())
    .apply<lbcrypto::CryptoContextImpl<lbcrypto::DCRTPoly>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        wrapped.method("Enable",
            static_cast<void (WrappedT::*)(lbcrypto::PKESchemeFeature)>(&WrappedT::Enable));
        wrapped.method("GetRingDimension", &WrappedT::GetRingDimension);
        wrapped.method("KeyGen", &WrappedT::KeyGen);
        wrapped.method("EvalMultKeyGen", &WrappedT::EvalMultKeyGen);
        wrapped.method("EvalRotateKeyGen", &WrappedT::EvalRotateKeyGen);
        wrapped.module().method("EvalRotateKeyGen", [](WrappedT& w,
                                                       const lbcrypto::PrivateKey<lbcrypto::DCRTPoly> privateKey,
                                                       jlcxx::ArrayRef<int64_t> index_list_ref) {
            std::vector<int32_t> index_list(index_list_ref.size());
            for (std::size_t i = 0; i < index_list_ref.size(); i++) {
              index_list[i] = index_list_ref[i];
            }
            w.EvalRotateKeyGen(privateKey, index_list);
          });
        // Note: one should also wrap actual `MakeCKKSPackedPlaintext` (omitted due to laziness)
        wrapped.module().method("MakeCKKSPackedPlaintext", [](WrappedT& w,
                                                              jlcxx::ArrayRef<double> value_ref,
                                                              size_t scaleDeg = 1,
                                                              uint32_t level = 0) {
            std::vector<double> value(value_ref.size());
            for (std::size_t i = 0; i < value_ref.size(); i++) {
              value[i] = value_ref[i];
            }
            return w.MakeCKKSPackedPlaintext(value);
          });
        wrapped.method("Encrypt",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(const lbcrypto::PublicKey<lbcrypto::DCRTPoly>,
                                      lbcrypto::Plaintext) const>(&WrappedT::Encrypt));
        wrapped.method("EvalAdd",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>,
                                      lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>) const>(&WrappedT::EvalAdd));
        wrapped.method("EvalSub",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>,
                                      lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>) const>(&WrappedT::EvalSub));
        wrapped.method("EvalMult",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>,
                                      lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>) const>(&WrappedT::EvalMult));
        wrapped.method("EvalMult",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>,
                                      double) const>(&WrappedT::EvalMult));
        wrapped.method("EvalRotate", &WrappedT::EvalRotate);
        wrapped.method("Decrypt",
            static_cast<lbcrypto::DecryptResult
                        (WrappedT::*)(lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>,
                                      const lbcrypto::PrivateKey<lbcrypto::DCRTPoly>,
                                      lbcrypto::Plaintext*)>(&WrappedT::Decrypt));
        wrapped.method("Decrypt",
            static_cast<lbcrypto::DecryptResult
                        (WrappedT::*)(const lbcrypto::PrivateKey<lbcrypto::DCRTPoly>,
                                      lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>,
                                      lbcrypto::Plaintext*)>(&WrappedT::Decrypt));
        wrapped.method("EvalBootstrapSetup", &WrappedT::EvalBootstrapSetup);
        wrapped.method("EvalBootstrapKeyGen", &WrappedT::EvalBootstrapKeyGen);
        wrapped.method("EvalBootstrap", &WrappedT::EvalBootstrap);
      });
}

void wrap_GenCryptoContext(jlcxx::Module& mod) {
  mod.method("GenCryptoContext",
      &lbcrypto::GenCryptoContext<lbcrypto::CryptoContextCKKSRNS>);
}


JLCXX_MODULE define_julia_module(jlcxx::Module& mod) {
  // Enums
  wrap_PKESchemeFeature(mod);
  wrap_ScalingTechnique(mod);
  wrap_SecretKeyDist(mod);
  wrap_DistributionType(mod);
  wrap_SecurityLevel(mod);

  // Classes
  wrap_CryptoContextCKKSRNS(mod);
  wrap_FHECKKSRNS(mod);
  wrap_Params(mod);
  wrap_CCParams(mod);
  wrap_Serializable(mod);
  wrap_DCRTPoly(mod);
  wrap_PrivateKeyImpl(mod);
  wrap_PublicKeyImpl(mod);
  wrap_KeyPair(mod);
  wrap_PlaintextImpl(mod);
  wrap_Plaintext(mod);
  wrap_CiphertextImpl(mod);
  wrap_DecryptResult(mod);
  wrap_CryptoContextImpl(mod);

  // Functions
  wrap_GenCryptoContext(mod);
}
