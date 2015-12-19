#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isMoreThanThird(int num, vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == num) ++count;
    }
    if (count > n / 3)
      return true;
    else
      return false;
  }

  vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result;
    if (n == 0) return result;

    int count1 = 0, count2 = 0;
    int num1, num2;
    for (int i = 0; i < n; ++i) {
      if (count1 == 0) num1 = nums[i];
      if (count2 == 0 && nums[i] != num1) num2 = nums[i];
      if (nums[i] == num1) ++count1;
      if (nums[i] == num2) ++count2;
      if (count1 != 0 && count2 != 0 && nums[i] != num1 && nums[i] != num2) {
        --count1;
        --count2;
      }
    }
    if (isMoreThanThird(num1, nums)) result.push_back(num1);
    if (isMoreThanThird(num2, nums) && num1 != num2) result.push_back(num2);
    return result;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}