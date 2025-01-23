#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_DCRTPoly(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::DCRTPoly>("DCRTPoly");
}
