#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    const int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return 1;
    int num = 1, i, temp = nums[1];
    for (i = 2; i < n; ++i)
      if (nums[i] != nums[i - 2]) {
        nums[num++] = temp;
        temp = nums[i];
      }
    nums[num++] = temp;
    return num;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}