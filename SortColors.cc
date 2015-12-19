#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    const int n = nums.size();
    if (n <= 1) return;
    int i = 0, j = n - 1;
    int cur = i;
    while (cur <= j) {
      if (nums[cur] == 0) {
        if (cur > i) {
          swap(nums[i++], nums[cur]);
        } else {
          ++cur;
          ++i;
        }
      } else if (nums[cur] == 2) {
        if (cur < j)
          swap(nums[j--], nums[cur]);
        else
          return;
      } else
        ++cur;
    }
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}