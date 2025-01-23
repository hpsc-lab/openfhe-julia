#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

// Required until https://github.com/JuliaInterop/CxxWrap.jl/issues/455 has been solved
#ifdef __APPLE__
    #undef JLCXX_HAS_RANGES
#endif

// BEGIN: <openfhe>/src/pke/include/constants.h
// Note: These functions wrap all enums in the OpenFHE source file `.../constants.h`

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

void wrap_ScalingTechnique(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::ScalingTechnique>("ScalingTechnique", jlcxx::julia_type("CppEnum"));
  mod.set_const("FIXEDMANUAL", lbcrypto::FIXEDMANUAL);
  mod.set_const("FIXEDAUTO", lbcrypto::FIXEDAUTO);
  mod.set_const("FLEXIBLEAUTO", lbcrypto::FLEXIBLEAUTO);
  mod.set_const("FLEXIBLEAUTOEXT", lbcrypto::FLEXIBLEAUTOEXT);
  mod.set_const("NORESCALE", lbcrypto::NORESCALE);
  mod.set_const("INVALID_RS_TECHNIQUE", lbcrypto::INVALID_RS_TECHNIQUE);
}

void wrap_ProxyReEncryptionMode(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::ProxyReEncryptionMode>("ProxyReEncryptionMode", jlcxx::julia_type("CppEnum"));
  mod.set_const("NOT_SET", lbcrypto::NOT_SET);
  mod.set_const("INDCPA", lbcrypto::INDCPA);
  mod.set_const("FIXED_NOISE_HRA", lbcrypto::FIXED_NOISE_HRA);
  mod.set_const("NOISE_FLOODING_HRA", lbcrypto::NOISE_FLOODING_HRA);
}

void wrap_MultipartyMode(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::MultipartyMode>("MultipartyMode", jlcxx::julia_type("CppEnum"));
  mod.set_const("INVALID_MULTIPARTY_MODE", lbcrypto::INVALID_MULTIPARTY_MODE);
  mod.set_const("FIXED_NOISE_MULTIPARTY", lbcrypto::FIXED_NOISE_MULTIPARTY);
  mod.set_const("NOISE_FLOODING_MULTIPARTY", lbcrypto::NOISE_FLOODING_MULTIPARTY);
}

void wrap_ExecutionMode(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::ExecutionMode>("ExecutionMode", jlcxx::julia_type("CppEnum"));
  mod.set_const("EXEC_EVALUATION", lbcrypto::EXEC_EVALUATION);
  mod.set_const("EXEC_NOISE_ESTIMATION", lbcrypto::EXEC_NOISE_ESTIMATION);
}

void wrap_DecryptionNoiseMode(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::DecryptionNoiseMode>("DecryptionNoiseMode", jlcxx::julia_type("CppEnum"));
  mod.set_const("FIXED_NOISE_DECRYPT", lbcrypto::FIXED_NOISE_DECRYPT);
  mod.set_const("NOISE_FLOODING_DECRYPT", lbcrypto::NOISE_FLOODING_DECRYPT);
}

void wrap_KeySwitchTechnique(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::KeySwitchTechnique>("KeySwitchTechnique", jlcxx::julia_type("CppEnum"));
  mod.set_const("INVALID_KS_TECH", lbcrypto::INVALID_KS_TECH);
  mod.set_const("BV", lbcrypto::BV);
  mod.set_const("HYBRID", lbcrypto::HYBRID);
}

void wrap_EncryptionTechnique(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::EncryptionTechnique>("EncryptionTechnique", jlcxx::julia_type("CppEnum"));
  mod.set_const("STANDARD", lbcrypto::STANDARD);
  mod.set_const("EXTENDED", lbcrypto::EXTENDED);
}

void wrap_MultiplicationTechnique(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::MultiplicationTechnique>("MultiplicationTechnique", jlcxx::julia_type("CppEnum"));
  mod.set_const("BEHZ", lbcrypto::BEHZ);
  mod.set_const("HPS", lbcrypto::HPS);
  mod.set_const("HPSPOVERQ", lbcrypto::HPSPOVERQ);
  mod.set_const("HPSPOVERQLEVELED", lbcrypto::HPSPOVERQLEVELED);
}

void wrap_PlaintextEncodings(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::PlaintextEncodings>("PlaintextEncodings", jlcxx::julia_type("CppEnum"));
  mod.set_const("INVALID_ENCODING", lbcrypto::INVALID_ENCODING);
  mod.set_const("COEF_PACKED_ENCODING", lbcrypto::COEF_PACKED_ENCODING);
  mod.set_const("PACKED_ENCODING", lbcrypto::PACKED_ENCODING);
  mod.set_const("STRING_ENCODING", lbcrypto::STRING_ENCODING);
  mod.set_const("CKKS_PACKED_ENCODING", lbcrypto::CKKS_PACKED_ENCODING);
}

void wrap_LargeScalingFactorConstants(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::LargeScalingFactorConstants>("LargeScalingFactorConstants", jlcxx::julia_type("CppEnum"));
  mod.set_const("MAX_BITS_IN_WORD", lbcrypto::MAX_BITS_IN_WORD);
  mod.set_const("MAX_LOG_STEP", lbcrypto::MAX_LOG_STEP);
}

void wrap_NOISE_FLOODING(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::NoiseFlooding>("NoiseFlooding", jlcxx::julia_type("CppEnum"));
  mod.set_const("MP_SD", lbcrypto::MP_SD);
  mod.set_const("PRE_SD", lbcrypto::PRE_SD);
  mod.set_const("NUM_MODULI_MULTIPARTY", lbcrypto::NUM_MODULI_MULTIPARTY);
  mod.set_const("MULTIPARTY_MOD_SIZE", lbcrypto::MULTIPARTY_MOD_SIZE);
}

void wrap_COMPRESSION_LEVEL(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::COMPRESSION_LEVEL>("COMPRESSION_LEVEL", jlcxx::julia_type("CppEnum"));
  mod.set_const("COMPACT", lbcrypto::COMPACT);
  mod.set_const("SLACK", lbcrypto::SLACK);
}

// END: <openfhe>/src/pke/include/constants.h

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

void wrap_SCHEME(jlcxx::Module& mod) {
  mod.add_bits<lbcrypto::SCHEME>("SCHEME", jlcxx::julia_type("CppEnum"));
  mod.set_const("INVALID_SCHEME", lbcrypto::INVALID_SCHEME);
  mod.set_const("CKKSRNS_SCHEME", lbcrypto::CKKSRNS_SCHEME);
  mod.set_const("BFVRNS_SCHEME", lbcrypto::BFVRNS_SCHEME);
  mod.set_const("BGVRNS_SCHEME", lbcrypto::BGVRNS_SCHEME);
}
