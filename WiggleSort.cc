
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

/* Wiggle Sort
Problem Description:
Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1]
>= nums[2] <= nums[3]....
For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2,
5, 3, 4].
The final sorted nums needs to satisfy two conditions:
If i is odd, then nums[i] >= nums[i - 1];
If i is even, then nums[i] <= nums[i - 1].
The code is just to fix the orderings of nums that do not satisfy 1 and 2.*/

class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; i++)
      if (((i & 1) && nums[i] < nums[i - 1]) ||
          (!(i & 1) && nums[i] > nums[i - 1]))
        swap(nums[i], nums[i - 1]);
  }
};

int main(int argc, char const* argv[]) { return 0; }