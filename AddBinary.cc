#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <sstream>



using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    if (a.size() == 0) return b;
    if (b.size() == 0) return a;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    vector<int> res;
    while (i >= 0 && j >= 0) {
      int digit = (int)(a[i] - '0' + b[j] - '0') + carry;
      carry = digit / 2;
      digit %= 2;
      res.push_back(digit);
      i--;
      j--;
    }
    while (i >= 0) {
      int digit = (int)(a[i] - '0') + carry;
      carry = digit / 2;
      digit %= 2;
      res.push_back(digit);
      i--;
    }
    while (j >= 0) {
      int digit = (int)(b[j] - '0') + carry;
      carry = digit / 2;
      digit %= 2;
      res.push_back(digit);
      j--;
    }
    if (carry > 0) {
      res.push_back(carry);
    }

    reverse(res.begin(), res.end());
    stringstream  stream_;
    for (int i = 0; i < res.size(); ++i) {
      stream_ << res[i];
    }
    return stream_.str();
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  Solution sol;
  cout << sol.addBinary( "11", "1") << endl;

  return 0;
}