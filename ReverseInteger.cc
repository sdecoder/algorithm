#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    bool isPositive = true;
    long long para = x;
    if (para < 0) {
      isPositive = false;
      para *= -1;
    }
    long long res = 0;
    while (para) {
      res = res * 10 + para % 10;
      para /= 10;
    }
    if (res > INT_MAX)
      return 0;
    if (!isPositive)
      return res * -1;
    else
      return res;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}