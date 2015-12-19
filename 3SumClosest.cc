#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>


#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int> &num, int target) {
    int min = INT_MAX;
    int result = 0;

     sort(num.begin(), num.end() );

    for (int i = 0; i < num.size(); i++) {
      int j = i + 1;
      int k = num.size() - 1;
      while (j < k) {
        int sum = num[i] + num[j] + num[k];
        int diff = abs(sum - target);

        if (diff == 0) return target;

        if (diff < min) {
          min = diff;
          result = sum;
        }
        if (sum <= target) {
          j++;
        } else {
          k--;
        }
      }
    }

    return result;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
