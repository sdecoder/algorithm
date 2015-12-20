#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>

using namespace std;

class Solution {
 public:
  int search(int A[], int n, int target) {
    int l = 0, r = n - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (A[m] == target) return m;
      if (A[m] >= A[l]) {
        if (A[l] <= target && target < A[m])
          r = m - 1;
        else
          l = m + 1;
      } else {
        if (A[m] < target && target <= A[r])
          l = m + 1;
        else
          r = m - 1;
      }
    }
    return -1;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}