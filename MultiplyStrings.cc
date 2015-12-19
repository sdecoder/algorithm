#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string multiply(string num1, string num2) {
    // 先把string翻转

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    const int length_ = num1.size() + num2.size();

    int d[length_];
    memset(d, 0, sizeof(int) * length_);
    for (int i = 0; i < num1.size(); i++) {
      for (int j = 0; j < num2.size(); j++) {
        d[i + j] += (num1[i] - '0') * (num2[j] - '0');
      }
    }

    stringstream sstream_;
    for (int i = 0; i < length_; i++) {
      int digit = d[i] % 10;  // 当前位
      int carry = d[i] / 10;  // 进位
      if (i + 1 < length_) {
        d[i + 1] += carry;
      }
      sstream_ << digit;  // prepend

    }


    string result = sstream_.str();
   // cout << "[dbg] result: " << result << endl;
    int cur = result.size() - 1;
    while (true) {
      if (result[cur] == '0' && cur > 0)
        cur--;
      else
        break;
    }

    string final = result.substr(0, cur +1 );
    reverse(final.begin(), final.end());
    return final;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  Solution sol;
  cout << sol.multiply("123", "123") << endl;
  return 0;
}