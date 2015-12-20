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
  bool num[3][9][9];
  void solveSudoku(vector<vector<char> > &board) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 9; j++) {
        for (int k = 0; k < 9; k++) {
          num[i][j][k] = true;
        }
      }
    }
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (isInteger(board[i][j])) {
          num[0][i][board[i][j] - '1'] = false;
          num[1][j][board[i][j] - '1'] = false;
          num[2][i / 3 * 3 + j / 3][board[i][j] - '1'] = false;
        }
      }
    }
    fillValidSudoku(0, 0, board);
  }

  bool fillValidSudoku(int i, int j, vector<vector<char> > &board) {
    if (j == 9) {
      i++;
      j = 0;
    }
    if (i == 9 && j == 0) {
      return true;
    } else if (isInteger(board[i][j])) {
      return fillValidSudoku(i, j + 1, board);
    } else {
      for (int k = 1; k <= 9; k++) {
        if (num[0][i][k - 1] && num[1][j][k - 1] &&
            num[2][i / 3 * 3 + j / 3][k - 1]) {
          board[i][j] = '0' + k;
          num[0][i][k - 1] = false;
          num[1][j][k - 1] = false;
          num[2][i / 3 * 3 + j / 3][k - 1] = false;
          if (fillValidSudoku(i, j + 1, board)) {
            return true;
          } else {
            num[0][i][k - 1] = true;
            num[1][j][k - 1] = true;
            num[2][i / 3 * 3 + j / 3][k - 1] = true;
            board[i][j] = '.';
          }
        }
      }
      return false;
    }
  }

  bool isInteger(char c) {
    if (c - '0' >= 1 && c - '0' <= 9) {
      return true;
    }
    return false;
  }
};

int main(int argc, char const *argv[]) { return 0; }