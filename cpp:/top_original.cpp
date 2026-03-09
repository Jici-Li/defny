// Dafny program top_original.dfy compiled into Cpp
#include "DafnyRuntime.h"
using namespace std::literals;
#include "top_original.h"
namespace _module  {

  uint32 __default::Maximum(DafnySequence<uint32> values)
  {
    uint32 max = 0;
    max = (values).select(0);
    uint32 _0_idx;
    _0_idx = (uint32)0;
    while ((_0_idx) < ((uint32)((values).size()))) {
      if ((max) < ((values).select(_0_idx))) {
        max = (values).select(_0_idx);
      }
      _0_idx = (_0_idx) + ((uint32)1);
    }
    return max;
  }
  void __default::Main(DafnySequence<DafnySequence<char>> __noArgsParameter __attribute__((unused)))
  {
    uint32 _0_x;
    uint32 _out0;
    _out0 = _module::__default::Maximum(DafnySequence<uint32>::Create({(uint32)1,(uint32)2,(uint32)3,(uint32)4}));
    _0_x = _out0;
    dafny_print(_0_x);
    dafny_print(DafnySequenceFromString("\n"s));
  }
}// end of namespace _module 
template <>
struct get_default<std::shared_ptr<_module::__default > > {
static std::shared_ptr<_module::__default > call() {
return std::shared_ptr<_module::__default >();}
};
int main(int argc, char *argv[]) {
  try {
    _module::__default::Main(dafny_get_args(argc, argv));
  }
  catch (DafnyHaltException & e) {
    std::cout << "Program halted: " << e.what() << std::endl;
  }
}
