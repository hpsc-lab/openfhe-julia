#ifndef OPENFHE_JULIA_ENUMS_H_
#define OPENFHE_JULIA_ENUMS_H_

#include "jlcxx/jlcxx.hpp"

void wrap_PKESchemeFeature(jlcxx::Module& mod);

void wrap_KeySwitchTechnique(jlcxx::Module& mod);

void wrap_ScalingTechnique(jlcxx::Module& mod);

void wrap_SecretKeyDist(jlcxx::Module& mod);

void wrap_DistributionType(jlcxx::Module& mod);

void wrap_SecurityLevel(jlcxx::Module& mod);

#endif // ifndef OPENFHE_JULIA_ENUMS_H_
