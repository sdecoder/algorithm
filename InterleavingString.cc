
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
#include <list>
#include <stack>

using namespace std;

class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
    if (l1 + l2 != l3) {
      return false;
    }
    bool f[l3 + 1][l1 + 1][l2 + 1];
    memset(f, false, sizeof(bool) * (l3 + 1) * (l1 + 1) * (l2 + 1));
    f[0][0][0] = true;
    for (int k = 1; k <= l3; k++) {
      for (int i = 0; i <= k && i <= l1; i++) {
        int j = k - i;
        if (j > l2) {
          continue;
        }
        if (i != 0 && f[k - 1][i - 1][j] && s1[i - 1] == s3[k - 1]) {
          f[k][i][j] = true;
        }
        if (j != 0 && f[k - 1][i][j - 1] && s2[j - 1] == s3[k - 1]) {
          f[k][i][j] = true;
        }
      }
    }
    return f[l3][l1][l2];
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}