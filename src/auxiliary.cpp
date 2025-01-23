#include "openfhe_julia/jlcxx_modified.h"
#include "openfhe.h"

// Required until https://github.com/JuliaInterop/CxxWrap.jl/issues/455 has been solved
#ifdef __APPLE__
    #undef JLCXX_HAS_RANGES
#endif

void wrap_auxiliary(jlcxx::Module& mod) {
  // Helper function for getting the text representation where only operator<< is defined
  mod.method("_to_string", [](lbcrypto::Plaintext& pt) {
      std::ostringstream stream;
      pt->PrintValue(stream);
      return stream.str();
    });
}
