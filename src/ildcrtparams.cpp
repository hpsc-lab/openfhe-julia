#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

#include "openfhe_julia/jlcxx_parameters.h"

void wrap_ILDCRTParams(jlcxx::Module& mod) {
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("ILDCRTParams")
    .apply<lbcrypto::ILDCRTParams<bigintdyn::ubint<long unsigned int>>>([](auto wrapped) {});
}

