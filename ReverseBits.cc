#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <limits.h>

using namespace std;

typedef unsigned int uint32_t;
class Solution {
public:
  uint32_t reverseBits(uint32_t n) {

    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
      result = (result << 1) + n % 2;
      n = n >> 1;
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}