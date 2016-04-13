#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int countRangeSum(vector<int> &nums, int lower, int upper) {
    if( nums.size() == 0) return 0;
    std::vector<int> sum;
    sum.clear();
    sum.push_back(nums[0]);
    for (int i = 1; i < nums.size(); ++i) {
      sum.push_back(sum[i - 1] + nums[i]);
    }

    int result = 0;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j <= i; ++j) {
        int interval_sum = j == 0 ? sum[i] : sum[i] - sum[j - 1];
        if (interval_sum >= lower && interval_sum <= upper)
          result++;
      }
    }

    return result;
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  std::vector<int> nums;
  nums.push_back(-2);
  nums.push_back(5);
  nums.push_back(-1);

  cout << "[dbg] result: " <<  sol.countRangeSum(nums, -2, 2) << endl;

  return 0;
}