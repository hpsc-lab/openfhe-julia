#ifndef OPENFHE_JULIA_JLCXX_PARAMETERS_H_
#define OPENFHE_JULIA_JLCXX_PARAMETERS_H_

#include "jlcxx/jlcxx.hpp"

namespace jlcxx
{
  template<> struct IsMirroredType<lbcrypto::CryptoContextCKKSRNS> : std::false_type { };
  template<> struct SuperType<lbcrypto::CCParams<lbcrypto::CryptoContextCKKSRNS>> { typedef lbcrypto::Params type; };
  template<> struct SuperType<lbcrypto::CiphertextImpl<lbcrypto::DCRTPoly>> { typedef lbcrypto::CryptoObject<lbcrypto::DCRTPoly> type; };
  template<> struct SuperType<lbcrypto::CryptoContextImpl<lbcrypto::DCRTPoly>> { typedef lbcrypto::Serializable type; };
  template<> struct SuperType<lbcrypto::EncodingParamsImpl> { typedef lbcrypto::Serializable type; };
}

#endif // ifndef OPENFHE_JULIA_JLCXX_PARAMETERS_H_
