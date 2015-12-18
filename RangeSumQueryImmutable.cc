#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>
#include <unordered_map>

using namespace std;

class NumArray {
  int buffer[1000000];

public:
  NumArray(vector<int> &nums) {
    if (nums.size() == 0)
      return;
    memset(buffer, 0, sizeof(buffer));
    buffer[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      buffer[i] = buffer[i - 1] + nums[i];
    }
  }

  int sumRange(int i, int j) {
    int ans = 0;
    if (i - 1 < 0)
      return buffer[j];
    else
      return buffer[j] - buffer[i - 1];

    // return ans;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}