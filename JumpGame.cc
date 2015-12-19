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

class Solution {
 public:
  bool canJump(int A[], int n) {
    if (n == 0 || n == 1) {
      return true;
    }
    int maxstep = A[0];
    for (int i = 1; i < n; i++) {
      if (maxstep == 0) return false;
      maxstep--;
      if (maxstep < A[i]) {
        maxstep = A[i];
      }
      if (maxstep + i >= n - 1) {
        return true;
      }
    }
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}