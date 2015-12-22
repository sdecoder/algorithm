#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*[LeetCode] 3Sum Smaller

Problem Description:

Given an array of n integers nums and a target, find the number of index
triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] +
nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.

Return 2. Because there are two triplets which sums are less than 2:

[-2, 0, 1]
[-2, 0, 3]
Follow up:
Could you solve it in O(n^2) runtime?

Sort nums first and then fix the left index (i) at each time while adjusting the
middle and right indexes (j, k). The following code should be
self-explanatory.*/

class Solution {
 public:
  int threeSumSmaller(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), ans = 0, i, j, k;
    for (int i = 0; i < n - 2; i++) {
      int j = i + 1, k = n - 1;
      while (j < k) {
        if (nums[i] + nums[j] + nums[k] >= target)
          k--;
        else {
          ans += (k - j);
          j++;
        }
      }
    }
    return ans;
  }
};
int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}