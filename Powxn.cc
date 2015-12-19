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
 public:
  double power(double x, int n) {
    if (n == 0) return 1;

    double v = power(x, n / 2);

    if (n % 2 == 0)
      return v * v;
    else
      return v * v * x;
  }

  double pow(double x, int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (n < 0)
      return 1.0 / power(x, -n);
    else
      return power(x, n);
  }
};

int main(int argc, char const *argv[]) { return 0; }