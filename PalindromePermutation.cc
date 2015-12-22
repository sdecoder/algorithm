#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

namespace solutionn2 {
class Solution {
 public:
  bool canPermutePalindrome(string s) {
    bitset<256> b;
    for (char c : s) b.flip(c);
    return b.count() < 2;
  }
};
}


class Solution {
 public:
  bool canPermutePalindrome(string s) {
    int odd = 0, counts[256] = {0};
    for (char c : s) odd += ++counts[c] & 1 ? 1 : -1;
    return odd <= 1;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}