
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
[LeetCode] Paint House

Problem Description:

There are a row of n houses, each house can be painted with one of the three
colors: red, blue or green. The cost of painting each house with a certain color
is different. You have to paint all the houses such that no two adjacent houses
have the same color.

The cost of painting each house with a certain color is represented by a n x 3
cost matrix. For example, costs[0][0] is the cost of painting house 0 with color
red;costs[1][2] is the cost of painting house 1 with color green, and so on...
Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

An interesting DP problem. This link posts a nice solution which gives
costs[i][j] a new meaning and modify it directly and so save the usage of
additional spaces.

Well, personally I would like to keep costs unmodified. I rewrite the code in
C++, a little verbose than the one in the above link:-)*/

class Solution {
 public:
  int minCost(vector<vector<int> >& costs) {
    if (costs.empty()) return 0;
    int n = costs.size(), r = 0, g = 0, b = 0;
    for (int i = 0; i < n; i++) {
      int rr = r, bb = b, gg = g;
      r = costs[i][0] + min(bb, gg);
      b = costs[i][1] + min(rr, gg);
      g = costs[i][2] + min(rr, bb);
    }
    return min(r, min(b, g));
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}