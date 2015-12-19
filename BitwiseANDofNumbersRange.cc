#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int rangeBitwiseAnd(int m, int n) {
  if (m > n) return 0;

  int i = 0;
  while (m != n && m != 0) {
    m >>= 1;
    n >>= 1;
    i++;
  }
  return m << i;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}