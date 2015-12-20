#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>

using namespace std;

class Solution {
 public:
  int jump(int A[], int n) {
    int ret = 0;
    int last = 0;
    int curr = 0;
    for (int i = 0; i < n; ++i) {
      if (i > last) {
        last = curr;
        ++ret;
      }
      curr = max(curr, i + A[i]);
    }

    return ret;
  }
};

int main(int argc, char const *argv[]) { return 0; }