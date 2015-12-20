#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }

    // initialize min length to be the input array length
    int result = nums.size();

    int i = 0;
    int sum = nums[0];

    for (int j = 0; j < nums.size();) {
      if (i == j) {
        if (nums[i] >= s) {
          return 1;  // if single elem is large enough
        } else {
          j++;

          if (j < nums.size()) {
            sum = sum + nums[j];
          } else {
            return result;
          }
        }
      } else {
        // if sum is large enough, move left cursor
        if (sum >= s) {
          result = min(j - i + 1, result);
          sum = sum - nums[i];
          i++;
          // if sum is not large enough, move right cursor
        } else {
          j++;

          if (j < nums.size()) {
            sum = sum + nums[j];
          } else {
            if (i == 0) {
              return 0;
            } else {
              return result;
            }
          }
        }
      }
    }

    return result;
  }
};

int main(int argc, char const* argv[]) { return 0; }