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
  int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > f(obstacleGrid.size(),
                           vector<int>(obstacleGrid[0].size()));

    f[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
    for (int i = 1; i < f.size(); i++)
      f[i][0] = obstacleGrid[i][0] == 1 ? 0 : f[i - 1][0];

    for (int i = 1; i < f[0].size(); i++)
      f[0][i] = obstacleGrid[0][i] == 1 ? 0 : f[0][i - 1];

    for (int i = 1; i < f.size(); i++)
      for (int j = 1; j < f[i].size(); j++)
        f[i][j] = obstacleGrid[i][j] == 1 ? 0 : f[i - 1][j] + f[i][j - 1];

    return f[f.size() - 1][f[0].size() - 1];
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}