
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
  int singleNumber(vector<int> &nums) {

    int result = 0;
    for (int i = 0; i < nums.size(); ++i) {
      result ^= nums[i];
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}