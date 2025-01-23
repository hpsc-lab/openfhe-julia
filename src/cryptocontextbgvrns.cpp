#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

// Required until https://github.com/JuliaInterop/CxxWrap.jl/issues/455 has been solved
#ifdef __APPLE__
    #undef JLCXX_HAS_RANGES
#endif

#include "openfhe_julia/jlcxx_parameters.h"

void wrap_CryptoContextBGVRNS(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::CryptoContextBGVRNS>("CryptoContextBGVRNS");
}
