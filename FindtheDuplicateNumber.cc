#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    while (true) {
      if (nums[nums[0]] == nums[0]) {
        return nums[0];
      } else {
        swap(nums[nums[0]], nums[0]);
      }
    }
    return -1;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}