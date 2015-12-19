#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#include <math.h>

#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  const int min(int a, int b) { return a < b ? a : b; }

 public:
  int numSquares(int n) {
    int d[n + 1];
    d[1] = 1;

    for (int i = 2; i <= n; i++) {
      int min_ = INT_MAX;
      int j = 1;
      while (j * j <= i) {
        if (j * j == i) {
          min_ = 1;
          break;
        }
        min_ = min(min_, d[i - j * j] + 1);
        ++j;
      }
      d[i] = min_;
    }
    return d[n];
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}