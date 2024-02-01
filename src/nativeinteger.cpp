#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_NativeInteger(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::NativeInteger>("NativeInteger");
}

