#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

#include "openfhe_julia/jlcxx_parameters.h"

void wrap_ubint(jlcxx::Module& mod) {
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("ubint")
    // Same as `BigInteger`
    .apply<bigintdyn::ubint<expdtype>>([](auto wrapped) {});
}

