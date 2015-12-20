#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  long long internalDivide(unsigned long long dividend,
                           unsigned long long divisor) {
    if (dividend < divisor) {
      return 0;
    }

    long long result = 1;
    unsigned long long tmp = divisor, left;

    while (tmp <= dividend) {
      left = dividend - tmp;
      tmp <<= 1;

      if (tmp > dividend) {
        break;
      } else {
        result <<= 1;
      }
    }

    return result + internalDivide(left, divisor);
  }

  int divide(int dividend, int divisor) {
    unsigned long long _dividend = abs((long long)dividend),
                       _divisor = abs((long long)divisor);
    bool positive = ((dividend >= 0) && (divisor > 0)) ||
                    ((dividend <= 0) && (divisor < 0));

    return positive ? internalDivide(_dividend, _divisor)
                    : (-1) * internalDivide(_dividend, _divisor);
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}