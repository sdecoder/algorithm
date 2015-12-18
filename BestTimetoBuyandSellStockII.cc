

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
  int maxProfit(vector<int> &prices) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int p = 0;
    for (int i = 1; i < prices.size(); ++i) {
      int delta = prices[i] - prices[i - 1];
      if (delta > 0) {
        p += delta;
      }
    }
    return p;
  }
};
int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}