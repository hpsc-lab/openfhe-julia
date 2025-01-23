#include "openfhe_julia/jlcxx_modified.h"
#include "openfhe.h"

void wrap_DecryptResult(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::DecryptResult>("DecryptResult");
}
