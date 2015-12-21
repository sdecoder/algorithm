#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>


using namespace std;

class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (nums.size() <= 1 || k < 1 || t < 0) return false;

    multiset<long long> mset;
    long long long_t = t;

    for (int i = 0; i < nums.size(); ++i) {
      if (mset.size() == k + 1) {
        auto it = mset.find(nums[i - k - 1]);
        mset.erase(it);
      }
      long long tmp = nums[i];
      auto it = mset.lower_bound(tmp - long_t);
      if (it != mset.end()) {
        long long diff = *it > tmp ? *it - tmp : tmp - *it;
        if (diff <= long_t) return true;
      }
      mset.emplace(nums[i]);
    }
    return false;
  }
};

int main(int argc, char const* argv[]) { return 0; }