#include <string>

#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

#include "openfhe_julia/jlcxx_parameters.h"
#include "openfhe_julia/enums.h"
#include "openfhe_julia/nativeinteger.h"
#include "openfhe_julia/cryptocontextckksrns.h"
#include "openfhe_julia/fheckksrns.h"
#include "openfhe_julia/params.h"
#include "openfhe_julia/ccparams.h"
#include "openfhe_julia/serializable.h"
#include "openfhe_julia/dcrtpoly.h"
#include "openfhe_julia/privatekeyimpl.h"
#include "openfhe_julia/publickeyimpl.h"
#include "openfhe_julia/keypair.h"
#include "openfhe_julia/plaintextimpl.h"
#include "openfhe_julia/cryptocontextproxy.h"
#include "openfhe_julia/cryptoobject.h"
#include "openfhe_julia/ciphertextimpl.h"
#include "openfhe_julia/decryptresult.h"
#include "openfhe_julia/ubint.h"
#include "openfhe_julia/ildcrtparams.h"
#include "openfhe_julia/encodingparamsimpl.h"
#include "openfhe_julia/cryptocontextimpl.h"
#include "openfhe_julia/auxiliary.h"


JLCXX_MODULE define_julia_module(jlcxx::Module& mod) {
  // Enums
  wrap_PKESchemeFeature(mod);
  wrap_KeySwitchTechnique(mod);
  wrap_ScalingTechnique(mod);
  wrap_SecretKeyDist(mod);
  wrap_DistributionType(mod);
  wrap_SecurityLevel(mod);

  // Classes
  wrap_NativeInteger(mod);
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
  auto CryptoContextProxy_type = wrap_CryptoContextProxy_type(mod);
  wrap_CryptoObject(mod);
  wrap_CiphertextImpl(mod);
  wrap_DecryptResult(mod);
  wrap_ubint(mod);
  wrap_ILDCRTParams(mod);
  wrap_EncodingParamsImpl(mod);
  wrap_CryptoContextImpl(mod);
  wrap_CryptoContextProxy_methods(CryptoContextProxy_type);

  // Functions
  wrap_GenCryptoContext(mod);
  wrap_auxiliary(mod);
}

