
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
  vector<int> singleNumber(vector<int> &nums) {
    int len = nums.size();
    int AxorB = 0;
    for (int i = 0; i < len; i++) {
      AxorB ^= nums[i];
    }
    int mask = AxorB & (~(AxorB - 1));
    int A = 0;
    int B = 0;
    for (int i = 0; i < len; i++) {
      if ((mask & nums[i]) == 0) {
        A ^= nums[i];
      } else {
        B ^= nums[i];
      }
    }
    return vector<int>({A, B});
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}