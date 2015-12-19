#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

const static int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool visited[1000][1000];
class Solution {
 public:
  bool exist(vector<vector<char> >& board, string word) {
    if (word.size() == 0) return false;

    
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        visited[i][j] = false;
      }
    }

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        if (board[i][j] == word[0]) {
          visited[i][j] = true;
          if (word.size() == 1 ||
              search(board, i, j, word.substr(1))) {
            return true;
          }
          visited[i][j] = false;
        }
      }
    }
    return false;
  }

  bool search(vector<vector<char> >& board, int i, int j, string word) {
    if (word.size() == 0) {
      return true;
    }

    for (int k = 0; k < 4; k++) {
      int ii = i + direction[k][0];
      int jj = j + direction[k][1];
      if (ii >= 0 && ii < board.size() && jj >= 0 && jj < board[i].size() &&
          board[ii][jj] == word[0] && visited[ii][jj] == false) {
        visited[ii][jj] = true;
        if (word.size() == 1 ||
            search(board, ii, jj, word.substr(1))) {
          return true;
        }
        visited[ii][jj] = false;
      }
    }
    return false;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}