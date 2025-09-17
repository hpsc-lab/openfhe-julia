#include "jlcxx/jlcxx.hpp"
#include "openfhe.h"

void wrap_auxiliary(jlcxx::Module& mod) {
  // TODO (GM): Is it fine to remove this? PrintValue is set to protected...
  // Helper function for getting the text representation where only operator<< is defined
  // mod.method("_to_string", [](lbcrypto::Plaintext& pt) {
  //     std::ostringstream stream;
  //     pt->PrintValue(stream);
  //     return stream.str();
  //   });
  mod.method("get_native_int", []() {
      return NATIVEINT;
    });
}
