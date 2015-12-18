#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>

using namespace std;

class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    vector<string> result;
    if (nums.size() == 0)
      return result;
    int start = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] - nums[i - 1] != 1) {
        if (start != nums[i - 1]) {
          char buffer[1000];
          sprintf(buffer, "%d->%d", start, nums[i - 1]);
          string reg(buffer);
          result.push_back(reg);
        } else {

          char buffer[1000];
          sprintf(buffer, "%d", start);
          string reg(buffer);
          result.push_back(reg);
        }
        start = nums[i];
      }
    }

    if (nums[nums.size() - 1] == start) {
      char buffer[1000];
      sprintf(buffer, "%d", start);
      string reg(buffer);
      result.push_back(reg);
    } else {
      char buffer[1000];
      sprintf(buffer, "%d->%d", start, nums[nums.size() - 1]);
      string reg(buffer);
      result.push_back(reg);
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}