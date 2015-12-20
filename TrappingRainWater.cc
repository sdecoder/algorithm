#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

#include <sstream>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
 public:
  int trap(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int water = 0;
    int maxIdx = 0;
    for (int i = 1; i < n; i++) {
      if (A[i] > A[maxIdx]) {
        maxIdx = i;
      }
    }
    int max = A[0];
    for (int i = 1; i < maxIdx; i++) {
      if (A[i] > max) {
        max = A[i];
      } else {
        water += max - A[i];
      }
    }
    max = A[n - 1];
    for (int i = n - 2; i > maxIdx; i--) {
      if (A[i] > max) {
        max = A[i];
      } else {
        water += max - A[i];
      }
    }
    return water;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}