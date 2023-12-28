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

// PrivateKey
struct PrivateKey {
  lbcrypto::PrivateKey<lbcrypto::DCRTPoly> pk;

  PrivateKey(lbcrypto::PrivateKey<lbcrypto::DCRTPoly> private_key);
};

PrivateKey::PrivateKey(lbcrypto::PrivateKey<lbcrypto::DCRTPoly> private_key)
  : pk(private_key) {}

// PublicKey
struct PublicKey {
  lbcrypto::PublicKey<lbcrypto::DCRTPoly> pk;

  PublicKey(lbcrypto::PublicKey<lbcrypto::DCRTPoly> public_key);
};

PublicKey::PublicKey(lbcrypto::PublicKey<lbcrypto::DCRTPoly> public_key)
  : pk(public_key) {}

// KeyPair
struct KeyPair {
  lbcrypto::KeyPair<lbcrypto::DCRTPoly> kp;

  KeyPair(lbcrypto::KeyPair<lbcrypto::DCRTPoly> key_pair);
  auto private_key();
  auto public_key();
};

KeyPair::KeyPair(lbcrypto::KeyPair<lbcrypto::DCRTPoly> key_pair)
  : kp(key_pair) {}

auto KeyPair::private_key() {
  return PrivateKey(kp.secretKey);
}

auto KeyPair::public_key() {
  return PublicKey(kp.publicKey);
}

// Plaintext
struct Plaintext {
  lbcrypto::Plaintext pt;

  Plaintext(lbcrypto::Plaintext plaintext);
  std::string to_string();
};

Plaintext::Plaintext(lbcrypto::Plaintext plaintext) : pt(plaintext) {}

std::string Plaintext::to_string() {
  std::ostringstream stream;
  pt->PrintValue(stream);
  return stream.str();
}

// Ciphertext
struct Ciphertext {
  lbcrypto::Ciphertext<lbcrypto::DCRTPoly> ct;

  Ciphertext(lbcrypto::Ciphertext<lbcrypto::DCRTPoly> ciphertext);
};

Ciphertext::Ciphertext(lbcrypto::Ciphertext<lbcrypto::DCRTPoly> ciphertext) : ct(ciphertext) {}

// Context
struct Context {
  lbcrypto::CryptoContext<lbcrypto::DCRTPoly> cc;

  Context(Parameters& parameters);
  auto GetRingDimension();
  auto KeyGen();
  void EvalMultKeyGen(const PrivateKey private_key);
  void EvalRotateKeyGen(const PrivateKey private_key, jlcxx::ArrayRef<int64_t> index_list);

  auto MakeCKKSPackedPlaintext(jlcxx::ArrayRef<double> value);
  auto Encrypt(const Plaintext plaintext, const PublicKey public_key);
  auto Encrypt(const PublicKey public_key, Plaintext plaintext);

  auto EvalAdd(Ciphertext ciphertext1, Ciphertext ciphertext2);
  auto EvalAdd(Ciphertext ciphertext, Plaintext plaintext);
  auto EvalAdd(Plaintext plaintext, Ciphertext ciphertext);
  auto EvalAdd(Ciphertext ciphertext, double constant);
  auto EvalAdd(double constant, Ciphertext ciphertext);

  auto EvalSub(Ciphertext ciphertext1, Ciphertext ciphertext2);
  auto EvalSub(Ciphertext ciphertext, Plaintext plaintext);
  auto EvalSub(Plaintext plaintext, Ciphertext ciphertext);
  auto EvalSub(Ciphertext ciphertext, double constant);
  auto EvalSub(double constant, Ciphertext ciphertext);

  auto EvalMult(Ciphertext ciphertext1, Ciphertext ciphertext2);
  auto EvalMult(Ciphertext ciphertext, Plaintext plaintext);
  auto EvalMult(Plaintext plaintext, Ciphertext ciphertext);
  auto EvalMult(Ciphertext ciphertext, double constant);
  auto EvalMult(double constant, Ciphertext ciphertext);

  auto EvalRotate(Ciphertext ciphertext, int32_t index);
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

void Context::EvalMultKeyGen(const PrivateKey private_key) {
  cc->EvalMultKeyGen(private_key.pk);
}

void Context::EvalRotateKeyGen(const PrivateKey private_key, jlcxx::ArrayRef<int64_t> index_list) {
  std::vector<int32_t> index_list_32(index_list.size());
  for (std::size_t i = 0; i < index_list.size(); i++) {
    index_list_32[i] = index_list[i];
  }

  cc->EvalRotateKeyGen(private_key.pk, index_list_32);
}

auto Context::MakeCKKSPackedPlaintext(jlcxx::ArrayRef<double> value) {
  std::vector<double> value_(value.size());
  for (std::size_t i = 0; i < value.size(); i++) {
    value_[i] = value[i];
  }

  return Plaintext(cc->MakeCKKSPackedPlaintext(value_));
}

auto Context::Encrypt(const Plaintext plaintext, const PublicKey public_key) {
  return cc->Encrypt(plaintext.pt, public_key.pk);
}
auto Context::Encrypt(const PublicKey public_key, Plaintext plaintext) {
  return Encrypt(plaintext, public_key);
}

auto Context::EvalAdd(Ciphertext ciphertext1, Ciphertext ciphertext2) {
  return Ciphertext(cc->EvalAdd(ciphertext1.ct, ciphertext2.ct));
}
auto Context::EvalAdd(Ciphertext ciphertext, Plaintext plaintext) {
  return Ciphertext(cc->EvalAdd(ciphertext.ct, plaintext.pt));
}
auto Context::EvalAdd(Plaintext plaintext, Ciphertext ciphertext) {
  return Ciphertext(cc->EvalAdd(plaintext.pt, ciphertext.ct));
}
auto Context::EvalAdd(Ciphertext ciphertext, double constant) {
  return Ciphertext(cc->EvalAdd(ciphertext.ct, constant));
}
auto Context::EvalAdd(double constant, Ciphertext ciphertext) {
  return Ciphertext(cc->EvalAdd(constant, ciphertext.ct));
}

auto Context::EvalSub(Ciphertext ciphertext1, Ciphertext ciphertext2) {
  return Ciphertext(cc->EvalSub(ciphertext1.ct, ciphertext2.ct));
}
auto Context::EvalSub(Ciphertext ciphertext, Plaintext plaintext) {
  return Ciphertext(cc->EvalSub(ciphertext.ct, plaintext.pt));
}
auto Context::EvalSub(Plaintext plaintext, Ciphertext ciphertext) {
  return Ciphertext(cc->EvalSub(plaintext.pt, ciphertext.ct));
}
auto Context::EvalSub(Ciphertext ciphertext, double constant) {
  return Ciphertext(cc->EvalSub(ciphertext.ct, constant));
}
auto Context::EvalSub(double constant, Ciphertext ciphertext) {
  return Ciphertext(cc->EvalSub(constant, ciphertext.ct));
}

auto Context::EvalMult(Ciphertext ciphertext1, Ciphertext ciphertext2) {
  return Ciphertext(cc->EvalMult(ciphertext1.ct, ciphertext2.ct));
}
auto Context::EvalMult(Ciphertext ciphertext, Plaintext plaintext) {
  return Ciphertext(cc->EvalMult(ciphertext.ct, plaintext.pt));
}
auto Context::EvalMult(Plaintext plaintext, Ciphertext ciphertext) {
  return Ciphertext(cc->EvalMult(plaintext.pt, ciphertext.ct));
}
auto Context::EvalMult(Ciphertext ciphertext, double constant) {
  return Ciphertext(cc->EvalMult(ciphertext.ct, constant));
}
auto Context::EvalMult(double constant, Ciphertext ciphertext) {
  return Ciphertext(cc->EvalMult(constant, ciphertext.ct));
}

auto Context::EvalRotate(Ciphertext ciphertext, int32_t index) {
  return Ciphertext(cc->EvalRotate(ciphertext.ct, index));
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

  mod.add_type<openfhe_julia::PrivateKey>("PrivateKey");
  mod.add_type<openfhe_julia::PublicKey>("PublicKey");
  mod.add_type<openfhe_julia::KeyPair>("KeyPair")
    .method("private_key", &openfhe_julia::KeyPair::private_key)
    .method("public_key", &openfhe_julia::KeyPair::public_key);

  mod.add_type<openfhe_julia::Plaintext>("Plaintext")
    .method("to_string", &openfhe_julia::Plaintext::to_string);
  mod.add_type<openfhe_julia::Ciphertext>("Ciphertext");

  mod.add_type<openfhe_julia::Context>("Context")
    .constructor<openfhe_julia::Parameters>()
    .method("GetRingDimension", &openfhe_julia::Context::GetRingDimension)
    .method("KeyGen", &openfhe_julia::Context::KeyGen)
    .method("EvalMultKeyGen", &openfhe_julia::Context::EvalMultKeyGen)
    .method("EvalRotateKeyGen", &openfhe_julia::Context::EvalRotateKeyGen)
    .method("MakeCKKSPackedPlaintext", &openfhe_julia::Context::MakeCKKSPackedPlaintext)
    .method("EvalAdd",
        static_cast<openfhe_julia::Ciphertext (openfhe_julia::Context::*)(openfhe_julia::Ciphertext, openfhe_julia::Ciphertext)>(&openfhe_julia::Context::EvalAdd))
    .method("EvalAdd",
        static_cast<openfhe_julia::Ciphertext (openfhe_julia::Context::*)(openfhe_julia::Ciphertext, openfhe_julia::Plaintext)>(&openfhe_julia::Context::EvalAdd))
    .method("EvalAdd",
        static_cast<openfhe_julia::Ciphertext (openfhe_julia::Context::*)(openfhe_julia::Plaintext, openfhe_julia::Ciphertext)>(&openfhe_julia::Context::EvalAdd))
    .method("EvalAdd",
        static_cast<openfhe_julia::Ciphertext (openfhe_julia::Context::*)(openfhe_julia::Ciphertext, double)>(&openfhe_julia::Context::EvalAdd))
    .method("EvalAdd",
        static_cast<openfhe_julia::Ciphertext (openfhe_julia::Context::*)(double, openfhe_julia::Ciphertext)>(&openfhe_julia::Context::EvalAdd))
    .method("EvalSub",
        static_cast<openfhe_julia::Ciphertext (openfhe_julia::Context::*)(openfhe_julia::Ciphertext, openfhe_julia::Ciphertext)>(&openfhe_julia::Context::EvalSub))
    .method("EvalSub",
        static_cast<openfhe_julia::Ciphertext (openfhe_julia::Context::*)(openfhe_julia::Ciphertext, openfhe_julia::Plaintext)>(&openfhe_julia::Context::EvalSub))
    .method("EvalSub",
        static_cast<openfhe_julia::Ciphertext (openfhe_julia::Context::*)(openfhe_julia::Plaintext, openfhe_julia::Ciphertext)>(&openfhe_julia::Context::EvalSub))
    .method("EvalSub",
        static_cast<openfhe_julia::Ciphertext (openfhe_julia::Context::*)(openfhe_julia::Ciphertext, double)>(&openfhe_julia::Context::EvalSub))
    .method("EvalSub",
        static_cast<openfhe_julia::Ciphertext (openfhe_julia::Context::*)(double, openfhe_julia::Ciphertext)>(&openfhe_julia::Context::EvalSub))
    .method("EvalMult",
        static_cast<openfhe_julia::Ciphertext (openfhe_julia::Context::*)(openfhe_julia::Ciphertext, openfhe_julia::Ciphertext)>(&openfhe_julia::Context::EvalMult))
    .method("EvalMult",
        static_cast<openfhe_julia::Ciphertext (openfhe_julia::Context::*)(openfhe_julia::Ciphertext, openfhe_julia::Plaintext)>(&openfhe_julia::Context::EvalMult))
    .method("EvalMult",
        static_cast<openfhe_julia::Ciphertext (openfhe_julia::Context::*)(openfhe_julia::Plaintext, openfhe_julia::Ciphertext)>(&openfhe_julia::Context::EvalMult))
    .method("EvalMult",
        static_cast<openfhe_julia::Ciphertext (openfhe_julia::Context::*)(openfhe_julia::Ciphertext, double)>(&openfhe_julia::Context::EvalMult))
    .method("EvalMult",
        static_cast<openfhe_julia::Ciphertext (openfhe_julia::Context::*)(double, openfhe_julia::Ciphertext)>(&openfhe_julia::Context::EvalMult))
    .method("EvalRotate", &openfhe_julia::Context::EvalRotate);

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
