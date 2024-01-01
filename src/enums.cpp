#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_PKESchemeFeature(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::PKESchemeFeature>("PKESchemeFeature", jlcxx::julia_type("CppEnum"));
  mod.set_const("PKE", lbcrypto::PKE);
  mod.set_const("KEYSWITCH", lbcrypto::KEYSWITCH);
  mod.set_const("PRE", lbcrypto::PRE);
  mod.set_const("LEVELEDSHE", lbcrypto::LEVELEDSHE);
  mod.set_const("ADVANCEDSHE", lbcrypto::ADVANCEDSHE);
  mod.set_const("MULTIPARTY", lbcrypto::MULTIPARTY);
  mod.set_const("FHE", lbcrypto::FHE);
  mod.set_const("SCHEMESWITCH", lbcrypto::SCHEMESWITCH);
}

void wrap_KeySwitchTechnique(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::KeySwitchTechnique>("KeySwitchTechnique", jlcxx::julia_type("CppEnum"));
  mod.set_const("INVALID_KS_TECH", lbcrypto::INVALID_KS_TECH);
  mod.set_const("BV", lbcrypto::BV);
  mod.set_const("HYBRID", lbcrypto::HYBRID);
}

void wrap_ScalingTechnique(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::ScalingTechnique>("ScalingTechnique", jlcxx::julia_type("CppEnum"));
  mod.set_const("FIXEDMANUAL", lbcrypto::FIXEDMANUAL);
  mod.set_const("FIXEDAUTO", lbcrypto::FIXEDAUTO);
  mod.set_const("FLEXIBLEAUTO", lbcrypto::FLEXIBLEAUTO);
  mod.set_const("FLEXIBLEAUTOEXT", lbcrypto::FLEXIBLEAUTOEXT);
  mod.set_const("NORESCALE", lbcrypto::NORESCALE);
  mod.set_const("INVALID_RS_TECHNIQUE", lbcrypto::INVALID_RS_TECHNIQUE);
}

void wrap_SecretKeyDist(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::SecretKeyDist>("SecretKeyDist", jlcxx::julia_type("CppEnum"));
  mod.set_const("GAUSSIAN", lbcrypto::GAUSSIAN);
  mod.set_const("UNIFORM_TERNARY", lbcrypto::UNIFORM_TERNARY);
  mod.set_const("SPARSE_TERNARY", lbcrypto::SPARSE_TERNARY);
}

void wrap_DistributionType(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::DistributionType>("DistributionType", jlcxx::julia_type("CppEnum"));
  mod.set_const("HEStd_uniform", lbcrypto::HEStd_uniform);
  mod.set_const("HEStd_error", lbcrypto::HEStd_error);
  mod.set_const("HEStd_ternary", lbcrypto::HEStd_ternary);
}

void wrap_SecurityLevel(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::SecurityLevel>("SecurityLevel", jlcxx::julia_type("CppEnum"));
  mod.set_const("HEStd_128_classic", lbcrypto::HEStd_128_classic);
  mod.set_const("HEStd_192_classic", lbcrypto::HEStd_192_classic);
  mod.set_const("HEStd_256_classic", lbcrypto::HEStd_256_classic);
  mod.set_const("HEStd_128_quantum", lbcrypto::HEStd_128_quantum);
  mod.set_const("HEStd_192_quantum", lbcrypto::HEStd_192_quantum);
  mod.set_const("HEStd_256_quantum", lbcrypto::HEStd_256_quantum);
  mod.set_const("HEStd_NotSet", lbcrypto::HEStd_NotSet);
}
