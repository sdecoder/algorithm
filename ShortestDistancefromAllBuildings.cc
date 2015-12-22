#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
You want to build a house on an empty land which reaches all buildings in the
shortest amount of distance. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
The distance is calculated using Manhattan Distance, where distance(p1, p2) =
|p2.x - p1.x| + |p2.y - p1.y|.

For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at
(0,2):

    1 - 0 - 2 - 0 - 1
    |   |   |   |   |
    0 - 0 - 0 - 0 - 0
    |   |   |   |   |
    0 - 0 - 1 - 0 - 0
The point (1,2) is an ideal empty land to build a house, as the total travel
distance of 3+3+1=7 is minimal. So return 7.

Note:
There will be at least one building. If it is not possible to build such house
according to the above rules, return -1.

Discuss:

https://leetcode.com/discuss/questions/oj/shortest-distance-from-all-buildings

*/
class Solution {
 public:
  int shortestDistance(vector<vector<int> > &grid) {
    int ret = 0;

    //    Get dimension
    int h = grid.size();
    if (!h) return ret;
    int w = grid[0].size();
    if (!w) return ret;

    //    Get all buildings
    typedef pair<int, int> Loc;
    vector<Loc> buildings;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
        if (grid[i][j] == 1) {
          buildings.push_back(Loc(i, j));
        }
      }

    size_t n = buildings.size();
    unsigned long long FullMask = ((unsigned long long)1 << n) - 1;

    //
    struct Rec {
      unsigned long long mask;
      int ttl;
    };

    ret = INT_MAX;
    vector<vector<Rec> > inf(h, vector<Rec>(w));
    for (int i = 0; i < buildings.size(); i++) {
      Loc &b = buildings[i];

      queue<Loc> q;
      vector<vector<bool> > visited(h, vector<bool>(w, false));
      vector<vector<bool> > inq(h, vector<bool>(w, false));
      q.push(b);
      visited[b.first][b.second] = inq[b.first][b.second] = true;

      int layerCnt = 1, layer = 0;
      while (!q.empty()) {
        Loc c = q.front();
        q.pop();
        visited[c.first][c.second] = true;

        // Mark
        if (grid[c.first][c.second] == 0) {
          inf[c.first][c.second].mask |= (unsigned long long)1 << i;
          inf[c.first][c.second].ttl += layer;
          if (i == (buildings.size() - 1)) {
            if (inf[c.first][c.second].mask == FullMask)
              ret = min(ret, inf[c.first][c.second].ttl);
          }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        for (int k = 0; k < 4; k++) {
          Loc nc(c.first + dy[k], c.second + dx[k]);
          if ((nc.first >= 0 && nc.first < h && nc.second >= 0 &&
               nc.second < w) &&
              (!grid[nc.first][nc.second] && !visited[nc.first][nc.second] &&
               (!inq[nc.first][nc.second]))) {
            q.push(nc);
            inq[nc.first][nc.second] = true;
          }
        }

        layerCnt--;
        if (!layerCnt) {
          layerCnt = q.size();
          layer++;
        }
      }
    }

    return ret == INT_MAX ? -1 : ret;
  }
};

int main(int argc, char const *argv[]) { return 0; }