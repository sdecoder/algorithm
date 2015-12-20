#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>

using namespace std;

class Solution {
 public:
  int firstMissingPositive(int A[], int n) {
    int i = 0;
    while (i < n) {
      if (A[i] != (i + 1) && A[i] >= 1 && A[i] <= n && A[A[i] - 1] != A[i])
        swap(A[i], A[A[i] - 1]);
      else
        i++;
    }
    for (i = 0; i < n; ++i)
      if (A[i] != (i + 1)) return i + 1;
    return n + 1;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}