#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int> > generateMatrix(int n) {
    int matrix[n][n];
    vector<vector<int> > result; 
    if (n <= 0) return result;
    

    int num = 1;
    int left = 0;
    int right = n - 1;
    int top = 0;
    int bottom = n - 1;
    while (num <= n * n) {
      int i;
      for (i = left; i <= right; i++) matrix[top][i] = num++;
      for (i = top + 1; i <= bottom; i++) matrix[i][right] = num++;
      if (top < bottom)
        for (i = right - 1; i >= left; i--) matrix[bottom][i] = num++;

      if (left < right)
        for (i = bottom - 1; i >= top + 1; i--) matrix[i][left] = num++;
      top++;
      left++;
      bottom--;
      right--;
    }

    for (int i = 0; i < n; ++i)
    {
      std::vector<int> row;
      for (int j = 0; j < n; ++j)
      {
        row.push_back(matrix[i][j]);
      }
      result.push_back(row);
    }

    return result;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  Solution sol; 
  sol.generateMatrix(10);
  return 0;
}