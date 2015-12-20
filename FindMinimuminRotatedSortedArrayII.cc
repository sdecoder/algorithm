#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

#include <sstream>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
  int min_(int a, int b) { return a <= b ? a : b; }

 public:
  int findMin(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int l = 0;
    int r = nums.size() - 1;
    int min = nums[0];
    while (l < r - 1) {
      int m = (l + r) / 2;
      if (nums[l] < nums[m]) {
        min = min_(nums[l], min);
        l = m + 1;
      } else if (nums[l] > nums[m]) {
        min = min_(nums[m], min);
        r = m - 1;
      } else {
        l++;
      }
    }
    min = min_(nums[r], min);
    min = min_(nums[l], min);
    return min;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}