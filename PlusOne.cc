#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    if (digits.size() == 0)
      return digits;
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
      int digit = (digits[i] + carry) % 10;
      carry = (digits[i] + carry) / 10;
      digits[i] = digit;
      if (carry == 0)
        return digits;
    }
    vector<int> res(digits.size() + 1, 0);
    res[0] = 1;
    return res;
  }
};

int main(int argc, char const *argv[]) {
  /* code */

  Solution sol;

  return 0;
}