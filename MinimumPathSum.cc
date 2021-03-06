#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 private:
  int f[1000][1000];

 public:
  int minPathSum(vector<vector<int> > &grid) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (grid.size() == 0 || grid[0].size() == 0) return 0;
    f[0][0] = grid[0][0];

    for (int i = 1; i < grid.size(); i++) f[i][0] = f[i - 1][0] + grid[i][0];
    for (int i = 1; i < grid[0].size(); i++) f[0][i] = f[0][i - 1] + grid[0][i];

    for (int i = 1; i < grid.size(); i++)
      for (int j = 1; j < grid[0].size(); j++)
        f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];

    return f[grid.size() - 1][grid[0].size() - 1];
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}