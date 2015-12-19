#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int> &height) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int size = height.size();
    int left = 0, right = size - 1;
    int max = 0;
    while (left < right) {
      int minheight = min(height[left], height[right]);
      int tmp = minheight * (right - left);
      max = max > tmp ? max : tmp;
      if (height[left] < height[right])
        left++;
      else
        right--;
    }
    return max;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}