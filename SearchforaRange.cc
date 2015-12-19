#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  vector<int> searchRange(int A[], int n, int target) {
    vector<int> range;
    range.push_back(findLeftMost(A, n, target));
    range.push_back(findRightMost(A, n, target));
    return range;
  }

  int findLeftMost(int A[], int n, int target) {
    int start = 0, end = n - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (target < A[mid])
        end = mid - 1;
      else if (target > A[mid])
        start = mid + 1;
      else
        end = mid - 1;
    }
    if (start >= 0 && start < n && A[start] == target) return start;
    return -1;
  }

  int findRightMost(int A[], int n, int target) {
    int start = 0, end = n - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (target < A[mid])
        end = mid - 1;
      else if (target > A[mid])
        start = mid + 1;
      else
        start = mid + 1;
    }
    if (end >= 0 && end < n && A[end] == target) return end;
    return -1;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}