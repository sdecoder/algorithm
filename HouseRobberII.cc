#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  // 1 2 3
 public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return max_(nums[0], nums[1]);
    return max_(robsub(nums, 0, nums.size() - 2),
                robsub(nums, 1, nums.size() - 1));
  }

 private:
  int max_(int a, int b) { return a > b ? a : b; }
  int robsub(vector<int>& nums, int s, int e) {
    int n = e - s + 1;
    int* d = new int[n];
    d[0] = nums[s];
    d[1] = max_(nums[s], nums[s + 1]);

    for (int i = 2; i < n; i++) {
      d[i] = max_(d[i - 2] + nums[s + i], d[i - 1]);
    }
    const int result = d[n - 1];
    delete d;
    return result;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}