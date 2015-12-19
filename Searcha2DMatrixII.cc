#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    return helper(matrix, 0, n - 1, 0, m - 1, target);
  }

  bool helper(vector<vector<int> >& matrix, int rowStart, int rowEnd,
              int colStart, int colEnd, int target) {
    if (rowStart > rowEnd || colStart > colEnd) {
      return false;
    }
    int rm = (rowStart + rowEnd) / 2, cm = (colStart + colEnd) / 2;
    if (matrix[rm][cm] == target) {
      return true;
    } else if (matrix[rm][cm] > target) {
      return helper(matrix, rowStart, rm - 1, colStart, cm - 1, target) ||
             helper(matrix, rm, rowEnd, colStart, cm - 1, target) ||
             helper(matrix, rowStart, rm - 1, cm, colEnd, target);
    } else {
      return helper(matrix, rm + 1, rowEnd, cm + 1, colEnd, target) ||
             helper(matrix, rm + 1, rowEnd, colStart, cm, target) ||
             helper(matrix, rowStart, rm, cm + 1, colEnd, target);
    }
  }
};

int main(int argc, char const* argv[]) { return 0; }