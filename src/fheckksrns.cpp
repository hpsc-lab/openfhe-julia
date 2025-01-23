// Required until https://github.com/JuliaInterop/CxxWrap.jl/issues/455 has been solved
#ifdef __APPLE__
    #undef JLCXX_HAS_RANGES
#endif

#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_FHECKKSRNS(jlcxx::Module& mod) {
  mod.method("GetBootstrapDepth",
      static_cast<uint32_t
                  (*)(const std::vector<uint32_t>&,
                  lbcrypto::SecretKeyDist)>(&lbcrypto::FHECKKSRNS::GetBootstrapDepth));
}
