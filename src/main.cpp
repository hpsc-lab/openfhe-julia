// C++ includes
#include <string>

// CxxWrap includes
#include "jlcxx/jlcxx.hpp"

// OpenFHE includes
#include "openfhe.h"

// Custom auxiliary types and functions
namespace openfhe_julia {

// Parameters
struct Parameters {
  lbcrypto::CCParams<lbcrypto::CryptoContextCKKSRNS> parameters;

  Parameters(uint32_t multDepth, uint32_t scaleModSize, uint32_t batchSize);
};

Parameters::Parameters(uint32_t multDepth, uint32_t scaleModSize, uint32_t batchSize) {
  parameters.SetMultiplicativeDepth(multDepth);
  parameters.SetScalingModSize(scaleModSize);
  parameters.SetBatchSize(batchSize);
}

// KeyPair
struct KeyPair {
  lbcrypto::KeyPair<lbcrypto::DCRTPoly> kp;

  KeyPair(lbcrypto::KeyPair<lbcrypto::DCRTPoly> key_pair);
};

KeyPair::KeyPair(lbcrypto::KeyPair<lbcrypto::DCRTPoly> key_pair) : kp(key_pair) {}

// Context
struct Context {
  lbcrypto::CryptoContext<lbcrypto::DCRTPoly> cc;

  Context(Parameters& parameters);
  auto GetRingDimension();
  auto KeyGen();
  auto EvalMultKeyGen(const KeyPair& key_pair);
};

Context::Context(Parameters& parameters)
  : cc(lbcrypto::GenCryptoContext(parameters.parameters)) {
  cc->Enable(lbcrypto::PKE);
  cc->Enable(lbcrypto::KEYSWITCH);
  cc->Enable(lbcrypto::LEVELEDSHE);
}

auto Context::GetRingDimension() {
  return cc->GetRingDimension();
}

auto Context::KeyGen() {
  return KeyPair(cc->KeyGen());
}

auto Context::EvalMultKeyGen(const KeyPair& key_pair) {
  return cc->EvalMultKeyGen(key_pair.kp.secretKey);
}

}


namespace jlcxx
{
  // template<> struct SuperType<lbcrypto::CCParams<lbcrypto::CryptoContextCKKSRNS>> { typedef lbcrypto::Params type; };
  // template<> struct IsMirroredType<lbcrypto::CryptoContextCKKSRNS> : std::false_type { };
}


JLCXX_MODULE define_julia_module(jlcxx::Module& mod)
{
  mod.add_type<openfhe_julia::Parameters>("Parameters")
    .constructor<uint32_t, uint32_t, uint32_t>();

  mod.add_type<openfhe_julia::KeyPair>("KeyPair");

  mod.add_type<openfhe_julia::Context>("Context")
    .constructor<openfhe_julia::Parameters>()
    .method("GetRingDimension", &openfhe_julia::Context::GetRingDimension)
    .method("KeyGen", &openfhe_julia::Context::KeyGen)
    .method("EvalMultKeyGen", &openfhe_julia::Context::EvalMultKeyGen);

  // // Class: CryptoContextCKKSRNS
  // mod.add_type<lbcrypto::CryptoContextCKKSRNS>("CryptoContextCKKSRNS");

  // // Class: Params
  // mod.add_type<lbcrypto::Params>("Params")
  //   .method("SetMultiplicativeDepth", &lbcrypto::Params::SetMultiplicativeDepth)
  //   .method("SetScalingModSize", &lbcrypto::Params::SetScalingModSize)
  //   .method("SetMultiplicativeDepth", &lbcrypto::Params::SetMultiplicativeDepth)
  //   .method("SetBatchSize", &lbcrypto::Params::SetBatchSize);

  // // Class: CCParams
  // mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("CCParams", jlcxx::julia_base_type<lbcrypto::Params>())
  //   .apply<lbcrypto::CCParams<lbcrypto::CryptoContextCKKSRNS>>([](auto wrapped) {});
}

// C++ def
//
// struct World
// {
//   World(const std::string& message = "default hello") : msg(message){}
//   void set(const std::string& msg) { this->msg = msg; }
//   std::string greet() { return msg; }
//   std::string msg;
//   ~World() { std::cout << "Destroying World with message " << msg << std::endl; }
// };

// CxxWrap'ed
//
// types.add_type<World>("World")
//   .constructor<const std::string&>()
//   .method("set", &World::set)
//   .method("greet", &World::greet);
