#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findPeakElement(const vector<int> &num) {
    int left = 0, right = num.size() - 1;
    while (left <= right) {
      if (left == right) return left;
      int mid = (left + right) / 2;
      if (num[mid] < num[mid + 1])
        left = mid + 1;
      else
        right = mid;
    }
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}