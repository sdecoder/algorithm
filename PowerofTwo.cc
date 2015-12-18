#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isPowerOfTwo(int n) {
    if (n <= 0)
      return false;
    const int factor = n & -n;
    if (n == factor)
      return true;
    return false;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}