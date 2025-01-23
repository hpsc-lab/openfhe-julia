#include "openfhe_julia/jlcxx_modified.h"
#include "openfhe.h"

void wrap_NativeInteger(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::NativeInteger>("NativeInteger");
}

