/*
Next Permutation My Submissions Question
Total Accepted: 53238 Total Submissions: 208606 Difficulty: Medium
Implement next permutation, which rearranges numbers into the lexicographically
next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible
order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding
outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
Subscribe to see which companies asked this question

Show Tags
Show Similar Problems
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int> &num) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int i = num.size() - 2;
    while (i >= 0 && num[i] >= num[i + 1]) {
      i--;
    }
    if (i < 0) {
      reverse(num.begin(), num.end());
    } else {
      int j = i + 2;
      while (j < num.size() && num[j] > num[i]) {
        j++;
      }
      j--;

      num[i] ^= num[j];
      num[j] ^= num[i];
      num[i] ^= num[j];
      reverse(num.begin() + i + 1, num.end());
    }
  }
};

int main(int argc, char const *argv[]) { return 0; }