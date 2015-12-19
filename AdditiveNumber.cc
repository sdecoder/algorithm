#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  bool isAdditiveNumber(string num) {
    int n = num.length();
    for (int i = 1; i <= n / 2; i++)
      for (int j = 1; max(i, j) <= n - i - j; j++)
        if (additive(i, j, num)) return true;
    return false;
  }

 private:
  bool additive(int i, int j, string& num) {
    if (num[i] == '0' && j > 1) return false;
    string a = num.substr(0, i);
    string b = num.substr(i, j);
    for (int k = i + j; k < num.length(); k += b.length()) {
      b.swap(a);
      b = add(a, b);
      string tail = num.substr(k);
      if (b.compare(tail.substr(0, b.size()))) return false;
    }
    return true;
  }
  string add(string& a, string& b) {
    string s;
    int i = a.size() - 1, j = b.size() - 1, c = 0;
    while (i >= 0 || j >= 0) {
      int d = (i >= 0 ? (a[i--] - '0') : 0) + (j >= 0 ? (b[j--] - '0') : 0) + c;
      s += (d % 10 + '0');
      c = d / 10;
    }
    if (c) s += ('0' + c);
    reverse(s.begin(), s.end());
    return s;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution sol;
  cout << sol.isAdditiveNumber("112358") << endl;
  cout << sol.isAdditiveNumber("199100199") << endl;
  return 0;
}