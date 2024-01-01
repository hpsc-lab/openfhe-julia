#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

#include "openfhe_julia/jlcxx_parameters.h"

void wrap_CryptoContextCKKSRNS(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::CryptoContextCKKSRNS>("CryptoContextCKKSRNS");
}
