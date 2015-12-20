#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>

using namespace std;

class Solution {
 public:
  int minDistance(string word1, string word2) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int row = word1.length() + 1;
    int col = word2.length() + 1;

    vector<vector<int> > f(row, vector<int>(col));

    for (int i = 0; i < row; i++) f[i][0] = i;
    for (int i = 0; i < col; i++) f[0][i] = i;

    for (int i = 1; i < row; i++)
      for (int j = 1; j < col; j++) {
        if (word1[i - 1] == word2[j - 1])
          f[i][j] = f[i - 1][j - 1];
        else
          f[i][j] = f[i - 1][j - 1] + 1;
        f[i][j] = min(f[i][j], min(f[i - 1][j] + 1, f[i][j - 1] + 1));
      }

    return f[row - 1][col - 1];
  }
};

int main(int argc, char const *argv[]) { return 0; }