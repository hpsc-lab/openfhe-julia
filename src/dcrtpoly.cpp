#include "openfhe_julia/jlcxx_modified.h"
#include "openfhe.h"

void wrap_DCRTPoly(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::DCRTPoly>("DCRTPoly");
}
