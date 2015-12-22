#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
Walls and Gates

You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to
represent INF as you may assume that the distance to a gate is less than
2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible
to reach a gate, it should be filled with INF.

For example, given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF


After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
没啥好说的，BFS。

*/

class Solution {
 public:
  void wallsAndGates(vector<vector<int> >& rooms) {
    if (rooms.empty() || rooms[0].empty()) return;
    int n = rooms.size(), m = rooms[0].size();
    queue<pair<int, int> > que;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (rooms[i][j] == 0) {
          ++cnt1;
          que.push({i, j});
        }
      }
    }
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    while (!que.empty()) {
      cnt2 = 0;
      for (int i = 0; i < cnt1; ++i) {
        auto u = que.front();
        que.pop();
        int x = u.first, y = u.second;
        for (int j = 0; j < 4; ++j) {
          int xx = x + dx[j], yy = y + dy[j];
          if (xx >= 0 && xx < n && yy >= 0 && yy < m &&
              rooms[xx][yy] > rooms[x][y]) {
            ++cnt2;
            rooms[xx][yy] = rooms[x][y] + 1;
            que.push({xx, yy});
          }
        }
      }
      cnt1 = cnt2;
    }
  }
};
int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}