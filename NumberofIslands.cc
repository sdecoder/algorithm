#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int R, C;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
bool **vis;
char **G;

void dfs(int pi, int pj) {
  vis[pi][pj] = true;
  int npi, npj;
  for (int i = 0; i < 4; i++) {
    npi = pi + dir[i][0];
    npj = pj + dir[i][1];
    if (0 <= npi && npi < R && 0 <= npj && npj < C && !vis[npi][npj] &&
        G[npi][npj] == '1')
      dfs(npi, npj);
  }
}

int numIslands(char **grid, int numRows, int numColumns) {
  G = grid;
  vis = (bool **)malloc(sizeof(bool *) * numRows);
  for (int i = 0; i < numRows; i++)
    vis[i] = (bool *)malloc(sizeof(bool) * numColumns);
  for (int i = 0; i < numRows; i++)
    for (int j = 0; j < numColumns; j++) vis[i][j] = false;
  int ans = 0;
  R = numRows;
  C = numColumns;
  for (int i = 0; i < numRows; i++)
    for (int j = 0; j < numColumns; j++)
      if (!vis[i][j] && G[i][j] == '1') {
        ans++;
        dfs(i, j);
      }
  for (int i = 0; i < numRows; i++) free(vis[i]);
  free(vis);
  return ans;
}

int main(int argc, char const *argv[]) { return 0; }