#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

#include "openfhe_julia/jlcxx_parameters.h"

void wrap_CryptoContextBGVRNS(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::CryptoContextBGVRNS>("CryptoContextBGVRNS");
}
