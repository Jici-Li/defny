#include "DafnyRuntime.h"
using namespace std::literals;
#include "top.h"
  uint32 Maximum_hls(const uint32 values[4]){
    uint32 max = values[0];
    for(int idx = 1; idx < 4; idx++) {
      if (max < values[idx]) {
        max = values[idx];
      }
    }
    return max;
  }
int main() {
  uint32 a[4] = {1,2,3,4};
  std::cout << Maximum_hls(a) << "\n";
  return 0;
 }
