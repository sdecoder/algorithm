#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximalSquare(vector<vector<char> >& matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return 0;

    const int n = matrix.size();
    const int m = matrix[0].size();
    int d[n][m];
    int max_ = 0;

    for (int i = 0; i < n; i++) {
      if (matrix[i][0] == '1') {
        d[i][0] = 1;
        max_ = 1;
      }
    }

    for (int j = 0; j < m; j++) {
      if (matrix[0][j] == '1') {
        d[0][j] = 1;
        max_ = 1;
      }
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        if (matrix[i][j] == '0')
          d[i][j] = 0;
        else {
          d[i][j] = min(min(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1]) + 1;
          max_ = max(max_, d[i][j]);
        }
      }
    }
    return max_ * max_;
  }
};

int main(int argc, char const* argv[]) { return 0; }