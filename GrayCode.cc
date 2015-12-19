#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> grayCode(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<int> result;
    int nSize = 1 << n;
    for (int i = 0; i < nSize; ++i) {
      result.push_back((i >> 1) ^ i);
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
