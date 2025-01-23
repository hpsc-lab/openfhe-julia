#ifndef OPENFHE_JULIA_ENUMS_H_
#define OPENFHE_JULIA_ENUMS_H_

#include "jlcxx_modified.h"

void wrap_PKESchemeFeature(jlcxx::Module& mod);

void wrap_ScalingTechnique(jlcxx::Module& mod);

void wrap_ProxyReEncryptionMode(jlcxx::Module& mod);

void wrap_MultipartyMode(jlcxx::Module& mod);

void wrap_ExecutionMode(jlcxx::Module& mod);

void wrap_DecryptionNoiseMode(jlcxx::Module& mod);

void wrap_KeySwitchTechnique(jlcxx::Module& mod);

void wrap_EncryptionTechnique(jlcxx::Module& mod);

void wrap_MultiplicationTechnique(jlcxx::Module& mod);

void wrap_PlaintextEncodings(jlcxx::Module& mod);

void wrap_LargeScalingFactorConstants(jlcxx::Module& mod);

void wrap_NOISE_FLOODING(jlcxx::Module& mod);

void wrap_COMPRESSION_LEVEL(jlcxx::Module& mod);

void wrap_SecretKeyDist(jlcxx::Module& mod);

void wrap_DistributionType(jlcxx::Module& mod);

void wrap_SecurityLevel(jlcxx::Module& mod);

void wrap_SCHEME(jlcxx::Module& mod);

#endif // ifndef OPENFHE_JULIA_ENUMS_H_
