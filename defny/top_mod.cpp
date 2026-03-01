#include <cstdint>

uint32_t Maximum_hls(const uint32_t values[4]) {
#pragma HLS INTERFACE ap_ctrl_hs port=return
  uint32_t max = values[0];
  for (int i = 1; i < 4; i++) {
    uint32_t v = values[i];
    if (max < v) 
    max = v;
  }
  return max;
}

#ifndef __SYNTHESIS__

#include "DafnyRuntime.h"
using namespace std::literals;
#include "top.h"

namespace _module {

  uint32 __default::Maximum(DafnySequence<uint32> values) {
    uint32_t a[4] = {
      (uint32_t)values.select(0),
      (uint32_t)values.select(1),
      (uint32_t)values.select(2),
      (uint32_t)values.select(3),
    };
    return (uint32)Maximum_hls(a);
  }

  void __default::Main(DafnySequence<DafnySequence<char>> __noArgsParameter __attribute__((unused))) {
    uint32 _0_x;
    uint32 _out0;
    _out0 = _module::__default::Maximum(
      DafnySequence<uint32>::Create({(uint32)1,(uint32)2,(uint32)3,(uint32)4})
    );
    _0_x = _out0;
    dafny_print(_0_x);
    dafny_print(DafnySequenceFromString("\n"s));
  }
} 

template <>
struct get_default<std::shared_ptr<_module::__default>> {
  static std::shared_ptr<_module::__default> call() {
    return std::shared_ptr<_module::__default>();
  }
};

int main(int argc, char *argv[]) {
  try {
    _module::__default::Main(dafny_get_args(argc, argv));
  }
  catch (DafnyHaltException & e) {
    std::cout << "Program halted: " << e.what() << std::endl;
  }
}

#endif 