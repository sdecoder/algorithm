#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#include <math.h>

#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

#define A(i) nums[(1 + 2 * (i)) % (n | 1)]

class Solution {
  int selectk(vector<int>& a, int low, int high, int k) {
    if (k <= 0) return -1;
    if (k > high - low + 1) return -1;
    int pivot = low + rand() % (high - low + 1);
    swap(a[low], a[pivot]);
    int m = low;
    int count = 1;

    for (int i = low + 1; i <= high; ++i) {
      if (a[i] > a[low]) {
        swap(a[++m], a[i]);
        count++;
      }
    }
    swap(a[m], a[low]);
    if (count > k) {
      return selectk(a, low, m - 1, k);
    } else if (count < k) {
      return selectk(a, m + 1, high, k - count);
    } else {
      return m;
    }
  }

  int nth_element(vector<int>& nums, int midptr) {
    const int idx = selectk(nums, 0, nums.size() - 1, midptr);
    if (idx == -1) return 0;
    return nums[idx];
  }

 public:
  void wiggleSort(vector<int>& nums) {
    const int n = nums.size();
    const int midptr = n / 2;
    const int mid = nth_element(nums, midptr);

    // Index-rewiring.

    // 3-way-partition-to-wiggly in O(n) time with O(1) space.
    int i = 0, j = 0, k = n - 1;
    while (j <= k) {
      if (A(j) > mid)
        swap(A(i++), A(j++));
      else if (A(j) < mid)
        swap(A(j), A(k--));
      else
        j++;
    }
  }
};


int main(int argc, char const *argv[])
{
  Solution s;
  return 0;
}