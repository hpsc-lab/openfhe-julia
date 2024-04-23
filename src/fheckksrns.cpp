#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_FHECKKSRNS(jlcxx::Module& mod) {
    mod.method("GetBootstrapDepth", &lbcrypto::FHECKKSRNS::GetBootstrapDepth);
}