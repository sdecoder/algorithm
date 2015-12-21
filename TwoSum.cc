#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    std::vector<int> output;
    map<int, int> map_;
    for (int i = 0; i < nums.size(); i++) {
      map_[nums[i]]=  i;
    }
    for (int i = 0; i < nums.size(); i++) {
      int val = target - nums[i];
      if (map_.find(val) != map_.end()) {
        int index = map_[val];
        if (index != i) {
          if (i < index) {
            output.push_back(i + 1);
            output.push_back(index + 1);

          } else {
            output.push_back(index + 1);
            output.push_back(i + 1);
          }
          return output;
        }
      }
    }
    return output;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}