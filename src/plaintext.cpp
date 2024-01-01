#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_Plaintext(jlcxx::Module& mod) {
  // `Plaintext`s need to be creatable
  mod.method("Plaintext", []() { return lbcrypto::Plaintext(); });
  // Helper function for getting the text representation
  mod.method("_to_string_plaintext", [](lbcrypto::Plaintext& pt) {
      std::ostringstream stream;
      pt->PrintValue(stream);
      return stream.str();
    });
}
