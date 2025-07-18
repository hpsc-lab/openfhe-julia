#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

#include "openfhe_julia/jlcxx_parameters.h"

void wrap_CryptoContextImpl(jlcxx::Module& mod) {
  // Source: <OpenFHE>/src/pke/include/cryptocontext.h
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("CryptoContextImpl",
      jlcxx::julia_base_type<lbcrypto::Serializable>())
    .apply<lbcrypto::CryptoContextImpl<lbcrypto::DCRTPoly>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;

        // Enable
        wrapped.method("Enable",
            static_cast<void (WrappedT::*)(lbcrypto::PKESchemeFeature)>(&WrappedT::Enable));

        // Key generation level
        wrapped.method("GetKeyGenLevel", &WrappedT::GetKeyGenLevel);
        wrapped.method("SetKeyGenLevel", &WrappedT::SetKeyGenLevel);

        wrapped.method("GetEncodingParams", &WrappedT::GetEncodingParams);
        wrapped.method("GetCyclotomicOrder", &WrappedT::GetCyclotomicOrder);
        wrapped.method("GetRingDimension", &WrappedT::GetRingDimension);
        wrapped.method("GetModulus", &WrappedT::GetModulus);
        wrapped.method("GetRootOfUnity", &WrappedT::GetRootOfUnity);

        wrapped.method("KeyGen", &WrappedT::KeyGen);

        wrapped.method("MakePackedPlaintext", &WrappedT::MakePackedPlaintext);

        using ParamType = lbcrypto::ILDCRTParams<bigintdyn::ubint<expdtype> >;
        wrapped.method("MakeCKKSPackedPlaintext",
            static_cast<lbcrypto::Plaintext (WrappedT::*)(const std::vector<double>&,
                                                          size_t,
                                                          uint32_t,
                                                          const std::shared_ptr<ParamType>,
                                                          usint) const>(&WrappedT::MakeCKKSPackedPlaintext));

        // Encrypt
        wrapped.method("Encrypt",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(const lbcrypto::Plaintext&,
                                      const lbcrypto::PublicKey<lbcrypto::DCRTPoly>) const>(&WrappedT::Encrypt));
        wrapped.method("Encrypt",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(const lbcrypto::PublicKey<lbcrypto::DCRTPoly>,
                                      lbcrypto::Plaintext) const>(&WrappedT::Encrypt));
        wrapped.method("Encrypt",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(const lbcrypto::Plaintext&,
                                      const lbcrypto::PrivateKey<lbcrypto::DCRTPoly>) const>(&WrappedT::Encrypt));
        wrapped.method("Encrypt",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(const lbcrypto::PrivateKey<lbcrypto::DCRTPoly>,
                                      lbcrypto::Plaintext) const>(&WrappedT::Encrypt));

        // Decrypt
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

        // EvalNegate
        wrapped.method("EvalNegate", &WrappedT::EvalNegate);

        // EvalAdd
        // ConstCiphertext + ConstCiphertext
        wrapped.method("EvalAdd",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>,
                                      lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>) const>(&WrappedT::EvalAdd));
        // ConstCiphertext + ConstPlaintext
        wrapped.method("EvalAdd",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>,
                                      lbcrypto::ConstPlaintext) const>(&WrappedT::EvalAdd));
        // ConstPlaintext + ConstCiphertext
        wrapped.method("EvalAdd",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(lbcrypto::ConstPlaintext,
                                      lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>) const>(&WrappedT::EvalAdd));
        // ConstCiphertext + double
        wrapped.method("EvalAdd",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>,
                                      double) const>(&WrappedT::EvalAdd));
        // double + ConstCiphertext
        wrapped.method("EvalAdd",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(double,
                                      lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>) const>(&WrappedT::EvalAdd));

        // EvalSub
        // ConstCiphertext - ConstCiphertext
        wrapped.method("EvalSub",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>,
                                      lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>) const>(&WrappedT::EvalSub));
        // ConstCiphertext - ConstPlaintext
        wrapped.method("EvalSub",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>,
                                      lbcrypto::ConstPlaintext) const>(&WrappedT::EvalSub));
        // ConstPlaintext - ConstCiphertext
        wrapped.method("EvalSub",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(lbcrypto::ConstPlaintext,
                                      lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>) const>(&WrappedT::EvalSub));
        // ConstCiphertext - double
        wrapped.method("EvalSub",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>,
                                      double) const>(&WrappedT::EvalSub));
        // double - ConstCiphertext
        wrapped.method("EvalSub",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(double,
                                      lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>) const>(&WrappedT::EvalSub));

        wrapped.method("EvalMultKeyGen", &WrappedT::EvalMultKeyGen);

        // EvalMult
        // ConstCiphertext * ConstCiphertext
        wrapped.method("EvalMult",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>,
                                      lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>) const>(&WrappedT::EvalMult));
        // ConstCiphertext * ConstPlaintext
        wrapped.method("EvalMult",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>,
                                      lbcrypto::ConstPlaintext) const>(&WrappedT::EvalMult));
        // ConstPlaintext * ConstCiphertext
        wrapped.method("EvalMult",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(lbcrypto::ConstPlaintext,
                                      lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>) const>(&WrappedT::EvalMult));
        // ConstCiphertext * double
        wrapped.method("EvalMult",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>,
                                      double) const>(&WrappedT::EvalMult));
        // double * ConstCiphertext
        wrapped.method("EvalMult",
            static_cast<lbcrypto::Ciphertext<lbcrypto::DCRTPoly>
                        (WrappedT::*)(double,
                                      lbcrypto::ConstCiphertext<lbcrypto::DCRTPoly>) const>(&WrappedT::EvalMult));

        wrapped.method("EvalSquare", &WrappedT::EvalSquare);

        wrapped.method("EvalMultNoRelin", &WrappedT::EvalMultNoRelin);
        wrapped.method("Relinearize", &WrappedT::Relinearize);
        wrapped.method("RelinearizeInPlace", &WrappedT::RelinearizeInPlace);

        wrapped.method("EvalRotate", &WrappedT::EvalRotate);
        wrapped.method("EvalRotateKeyGen", &WrappedT::EvalRotateKeyGen);

        wrapped.method("ComposedEvalMult", &WrappedT::ComposedEvalMult);
        wrapped.method("Rescale", &WrappedT::Rescale);
        wrapped.method("RescaleInPlace", &WrappedT::RescaleInPlace);
        wrapped.method("ModReduce", &WrappedT::ModReduce);
        wrapped.method("ModReduceInPlace", &WrappedT::ModReduceInPlace);

        wrapped.method("EvalSin", &WrappedT::EvalSin);
        wrapped.method("EvalCos", &WrappedT::EvalCos);
        wrapped.method("EvalLogistic", &WrappedT::EvalSin);
        wrapped.method("EvalDivide", &WrappedT::EvalDivide);

        wrapped.method("EvalSumKeyGen", &WrappedT::EvalSumKeyGen);
        wrapped.method("EvalSum", &WrappedT::EvalSum);

        wrapped.method("EvalBootstrapSetup", &WrappedT::EvalBootstrapSetup);
        wrapped.method("EvalBootstrapKeyGen", &WrappedT::EvalBootstrapKeyGen);
        wrapped.method("EvalBootstrap", &WrappedT::EvalBootstrap);

        //wrapped.method("Compress", &WrappedT::Compress);
      });

      // clear evaluation keys
      typedef lbcrypto::CryptoContextImpl<lbcrypto::DCRTPoly> WrappedT;    
      mod.method("ClearEvalMultKeys", static_cast<void (*)()>(&WrappedT::ClearEvalMultKeys));
      mod.method("ClearEvalMultKeys",
                 static_cast<void (*)(const lbcrypto::CryptoContext<lbcrypto::DCRTPoly>)>(&WrappedT::ClearEvalMultKeys));
      mod.method("ClearEvalMultKeys", static_cast<void (*)(const std::string&)>(&WrappedT::ClearEvalMultKeys));
      mod.method("ClearEvalSumKeys", static_cast<void (*)()>(&WrappedT::ClearEvalSumKeys));
      mod.method("ClearEvalSumKeys",
                 static_cast<void (*)(const lbcrypto::CryptoContext<lbcrypto::DCRTPoly>)>(&WrappedT::ClearEvalSumKeys));
      mod.method("ClearEvalSumKeys", static_cast<void (*)(const std::string&)>(&WrappedT::ClearEvalSumKeys));
      mod.method("ClearEvalAutomorphismKeys", static_cast<void (*)()>(&WrappedT::ClearEvalAutomorphismKeys));
      mod.method("ClearEvalAutomorphismKeys",
                 static_cast<void (*)(const lbcrypto::CryptoContext<lbcrypto::DCRTPoly>)>(&WrappedT::ClearEvalAutomorphismKeys));
      mod.method("ClearEvalAutomorphismKeys", static_cast<void (*)(const std::string&)>(&WrappedT::ClearEvalAutomorphismKeys));
}

void wrap_GenCryptoContext(jlcxx::Module& mod) {
  mod.method("GenCryptoContext",
      &lbcrypto::GenCryptoContext<lbcrypto::CryptoContextBFVRNS>);
  mod.method("GenCryptoContext",
      &lbcrypto::GenCryptoContext<lbcrypto::CryptoContextBGVRNS>);
  mod.method("GenCryptoContext",
      &lbcrypto::GenCryptoContext<lbcrypto::CryptoContextCKKSRNS>);
}
