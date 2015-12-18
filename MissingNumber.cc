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
  int missingNumber(vector<int> &nums) {
    int N = nums.size();
    long expected_sum = (1 + N) * N / 2;
    long real_sum = 0;
    for (int i = 0; i < N; i++) {
      real_sum += nums[i];
    }

    return expected_sum - real_sum;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}