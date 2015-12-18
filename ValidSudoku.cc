#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char> > &board) {
    int rowValid[10] = {0};                         //用于判断某一行是否合法，对于行来说这个数组可以重复使用
    int columnValid[9][10] = {0};   //用于判断某一列是否合法
    int subBoardValid[9][10] = {0}; //用于判断某一个九宫格是否合法
    for (int i = 0; i < 9; i++) {
      memset(rowValid, 0, sizeof(rowValid));
      for (int j = 0; j < 9; j++)
        if (board[i][j] != '.') {
          if (!checkValid(rowValid, board[i][j] - '0') ||
              !checkValid(columnValid[j], board[i][j] - '0') ||
              !checkValid(subBoardValid[i / 3 * 3 + j / 3], board[i][j] - '0'))
            return false;
        }
    }
    return true;
  }
  bool checkValid(int vec[], int val) {
    if (vec[val] == 1)
      return false;
    vec[val] = 1;
        return true;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}