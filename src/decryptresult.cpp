#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_DecryptResult(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::DecryptResult>("DecryptResult");
}
