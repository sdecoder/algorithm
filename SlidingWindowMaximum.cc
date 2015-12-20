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

/*
 Sliding Window Maximum My Submissions Question
Total Accepted: 17633 Total Submissions: 70829 Difficulty: Hard
Given an array nums, there is a sliding window of size k which is moving from
the very left of the array to the very right. You can only see the k numbers in
the window. Each time the sliding window mosves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note:
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty
array.*/

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    deque<int> q;
    for (int i = 0; i < nums.size(); ++i) {
      if (!q.empty() && q.front() == i - k) q.pop_front();
      while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
      q.push_back(i);
      if (i >= k - 1) res.push_back(nums[q.front()]);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }