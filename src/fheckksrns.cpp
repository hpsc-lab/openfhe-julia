#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_FHECKKSRNS(jlcxx::Module& mod) {
  mod.add_type<lbcrypto::FHECKKSRNS>("FHECKKSRNS")
    .method("EvalBootstrapSetup", 
            static_cast<void 
                        (*)(const lbcrypto::CryptoContextImpl<lbcrypto::DCRTPoly>& cc, std::vector<uint32_t> levelBudget,
                                    std::vector<uint32_t> dim1, uint32_t numSlots, uint32_t correctionFactor,
                                    bool precompute)>(&lbcrypto::FHECKKSRNS::EvalBootstrapSetup))
    .method("GetBootstrapDepth", 
            static_cast<uint32_t 
                        (*)(const std::vector<uint32_t>&,
                            lbcrypto::SecretKeyDist)>(&lbcrypto::FHECKKSRNS::GetBootstrapDepth));
}