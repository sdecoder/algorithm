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

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    std::vector<int> result;
    result.push_back(1);

    for (int i = 1; i < nums.size(); ++i) {
      result.push_back(result[i - 1] * nums[i - 1]);
    }

    int accum = nums[nums.size() - 1];
    for (int i = nums.size() - 2; i >= 1; --i) {

      result[i] = result[i] * accum;
      accum = accum * nums[i];
    }

    result[0] = accum;
    return result;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}