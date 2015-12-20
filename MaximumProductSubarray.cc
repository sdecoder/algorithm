/*Maximum Product Subarray My Submissions Question
Total Accepted: 47172 Total Submissions: 226095 Difficulty: Medium
Find the contiguous subarray within an array (containing at least one number)
which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

Subscribe to see which companies asked this question*/

#define LEN 100000
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
  int Max(int a, int b) { return a > b ? a : b; }

  int Min(int a, int b) { return a < b ? a : b; }

  int maxProduct(int A[], int n) {
    int i;
    int ans;

    int max[LEN];
    int min[LEN];
    max[0] = min[0] = A[0];
    ans = A[0];
    for (i = 1; i < n; ++i) {
      max[i] = Max(Max(A[i], max[i - 1] * A[i]), min[i - 1] * A[i]);
      min[i] = Min(Min(A[i], max[i - 1] * A[i]), min[i - 1] * A[i]);
      ans = Max(ans, max[i]);
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}