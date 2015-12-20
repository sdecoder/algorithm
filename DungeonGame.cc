
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
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
  int func(int value) {
    if (value > 0) return value;
    return 1;
  }

  int matrix[1000][1000];

 public:
  int calculateMinimumHP(vector<vector<int> > &dungeon) {
    int width = dungeon.size();
    int height = dungeon[0].size();
    // int[][] matrix= new int[width][height];
    memset(matrix, 0, sizeof(matrix));

    matrix[width - 1][height - 1] = func(1 - dungeon[width - 1][height - 1]);

    for (int i = height - 2; i >= 0; --i) {
      matrix[width - 1][i] =
          func(matrix[width - 1][i + 1] - dungeon[width - 1][i]);
    }

    for (int i = width - 2; i >= 0; --i) {
      matrix[i][height - 1] =
          func(matrix[i + 1][height - 1] - dungeon[i][height - 1]);
    }

    for (int dx = width - 2; dx >= 0; --dx) {
      for (int dy = height - 2; dy >= 0; --dy) {
        int value1 = matrix[dx + 1][dy];
        int value2 = matrix[dx][dy + 1];
        matrix[dx][dy] = value1 < value2 ? value1 : value2;
        matrix[dx][dy] = func(matrix[dx][dy] - dungeon[dx][dy]);
      }
    }


    return matrix[0][0];
  }
};

int main(int argc, char const *argv[]) { return 0; }