#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumTotal(vector<vector<int> > &triangle) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    const int numRow = triangle.size();
    vector<int> ibuffer;
    ibuffer.resize(numRow);

    // 从底到顶计算最小和
    for (int i = numRow - 1; i >= 0; --i) {
      vector<int> &row = triangle[i];

      for (int j = 0; j < row.size(); ++j) {
        if (i == numRow - 1)
          ibuffer[j] = row[j];
        else
          ibuffer[j] = min(row[j] + ibuffer[j], row[j] + ibuffer[j + 1]);
      }
    }

    return ibuffer[0];
  }
};

int main(int argc, char const *argv[]) { return 0; }