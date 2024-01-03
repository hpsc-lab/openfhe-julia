#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

#include "openfhe_julia/jlcxx_parameters.h"

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
        using ParamType = lbcrypto::ILDCRTParams<bigintdyn::ubint<long unsigned int> >;
        wrapped.method("MakeCKKSPackedPlaintext",
            static_cast<lbcrypto::Plaintext (WrappedT::*)(const std::vector<double>&,
                                                          size_t,
                                                          uint32_t,
                                                          const std::shared_ptr<ParamType>,
                                                          usint) const>(&WrappedT::MakeCKKSPackedPlaintext));
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
