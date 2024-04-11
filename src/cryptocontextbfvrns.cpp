#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

#include "openfhe_julia/jlcxx_parameters.h"

void wrap_CryptoContextBFVRNS(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::CryptoContextBFVRNS>("CryptoContextBFVRNS");
}
