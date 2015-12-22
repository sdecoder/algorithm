
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
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
[LeetCode] Best Meeting Point

Problem Description:

A group of two or more people wants to meet and minimize the total travel
distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home
of someone in the group. The distance is calculated using Manhattan Distance,
where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and (2,2):

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, as the total travel distance of
2+2+2=6 is minimal. So return 6.

Hint:

Try to solve it in one dimension first. How can this solution apply to the two
dimension case?
Since the distance is computed using the Manhattan Distance, we can decompose
this 2-d problem into two 1-d problems and combine (add) their solutions. In
fact, the best meeting point is just the point that comprised by the two best
meeting points in each dimension.

For the 1d case, the best meeting point is just the median point.

This post shares a nice Python code. However, translating it into C++ makes it
so ugly...

*/

class Solution {
 public:
  int minTotalDistance(vector<vector<int> >& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> ii, jj;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j]) {
          ii.push_back(i);
          jj.push_back(j);
        }
      }
    }
    sort(jj.begin(), jj.end());
    int c = ii.size(), s = 0, io = ii[c / 2], jo = jj[c / 2];
    for (int i : ii) s += abs(i - io);
    for (int j : jj) s += abs(j - jo);
    return s;
  }
};
int main(int argc, char const* argv[]) { return 0; }