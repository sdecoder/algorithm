#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
  int trailingZeroes(int n) {
    int ret = 0;
    while (n) {
      ret += n / 5;
      n /= 5;
    }
    return ret;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}