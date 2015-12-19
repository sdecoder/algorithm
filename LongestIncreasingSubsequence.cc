#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int* d = new int[nums.size()];
    for (int i = 0; i < nums.size(); ++i) {
      d[i] = nums[i];
    }
    int len = LISSEx(d, nums.size());  //, int result[])
    delete d;
    return len;
  }
  unsigned int LISSEx(const int array[], size_t length)  //, int result[])
  {
    unsigned int i, j, k, l, max;
    unsigned int liss[length];
    unsigned int pre[length];
    liss[0] = 0;
    for (i = 0; i < length; ++i) {
      pre[i] = i;
    }

    for (i = 1, max = 1; i < length; ++i) {
      j = 0, k = max - 1;
      while (k - j > 1) {
        l = (j + k) / 2;
        if (array[liss[l]] < array[i]) {
          j = l;
        } else {
          k = l;
        }
      }

      if (array[liss[j]] < array[i]) {
        j = k;
      }
      if (j == 0) {
        if (array[liss[0]] >= array[i]) {
          liss[0] = i;
          continue;
        }
      }
      if (j == max - 1) {
        if (array[liss[j]] < array[i]) {
          pre[i] = liss[j];
          liss[max++] = i;
          continue;
        }
      }

      pre[i] = liss[j - 1];
      liss[j] = i;
    }

    i = max - 1;
    k = liss[max - 1];

    /*while(pre[k] != k)
    {
        result[i--] = array[k];
        k = pre[k];
    }
    result[i] = array[k];  */
    return max;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
