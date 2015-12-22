/*[LeetCode#265] Paint House II
Problem:

There are a row of n houses, each house can be painted with one of the k colors.
The cost of painting each house with a certain color is different. You have to
paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k
cost matrix. For example, costs[0][0] is the cost of painting house 0 with color
0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find
the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?

Analysis:

复制代码
This problem is very elegant if you take the time comlexity constraint into
consideration.
It actually share the same dynamic programming idea as Paint House |.

If we continue follow the old coding structure, we definitely would end up with
the time complexity: O(nk^2).
level 1: n is the total number of houses we have to paint.
level 2: the first k represent for each house we need to try k colors.
level 3: the second k was caused by the process to search the minimum cost (if
not use certain color).

Apparently, if we want reach the time complexity O(nk), we have to optimize our
operation at level 3.
If we choose the color[i][j], how could we reduce the comparision between
(color[i-1][0] to color[i-1][k], except color[i-1][j])
And we know there are acutally extra comparisions, since fore each color, we
have to find the smallest amongst other colors.

There must be way to solve it, Right?
Yup!!! There is a magic skill for it!!!
Let us assume, we have "min_1" and "min_2".
min_1 : the lowest cost at previous stage.
min_2 : the 2nd lowest cost at previous stage.

And we have the minimum costs for all colors at previous stage.
color[i-1][k]

Then, iff we decide to paint house "i" with color "j", we can compute the
minimum cost of other colors at "i-1" stage through following way.
case 1: iff "color[i-1][j] == min_1", it means the min_1 actually records the
minimum value of color[i-1][j] (previous color is j), we have to use min_2;
case 2: iff "color[i-1][j] != min_1", it means min_1 is not the value of
color[i-1][j] (previous color is not j), we can use the min_1's color.
Note: iff "pre_min_1 == pre_min_2", it means there are two minimum costs,
anyway, no matter which color is pre_min_1, we can use pre_min_2.
----------------------------------------------------------
if (dp[j] != pre_min_1 || pre_min_1 == pre_min_2) {
    dp[j] = pre_min_1 + costs[i][j];
} else{
    dp[j] = pre_min_2 + costs[i][j];
}
----------------------------------------------------------
The way to maintain "min_1" and "min_2".
for (int i = 0; i < len; i++) {
    ...
    min_1 = Integer.MAX_VALUE;
    min_2 = Integer.MAX_VALUE;
    ...
    if (dp[j] <= min_1) {
        min_2 = min_1;
        min_1 = dp[j];
    } else if (dp[j] < min_2){
        min_2 = dp[j];
    }
}

Note:
To reduce the burden of handling case, we absolutely could start from i=0, when
we could assume all previous cost is 0 since we have no house.
复制代码
Solution:
*/

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

class Solution {
 public:
  int minCostII(std::vector<std::vector<int> > costs) {
    if (costs.size() == 0) return 0;
    int len = costs.size();
    int k = costs[0].size();
    int min_1 = 0, min_2 = 0;
    int pre_min_1, pre_min_2;
    int dp[k];
    for (int i = 0; i < len; i++) {
      pre_min_1 = min_1;
      pre_min_2 = min_2;
      min_1 = INT_MAX;
      min_2 = INT_MAX;
      for (int j = 0; j < k; j++) {
        if (dp[j] != pre_min_1 || pre_min_1 == pre_min_2) {
          dp[j] = pre_min_1 + costs[i][j];
        } else {
          dp[j] = pre_min_2 + costs[i][j];
        }
        if (dp[j] <= min_1) {
          min_2 = min_1;
          min_1 = dp[j];
        } else if (dp[j] < min_2) {
          min_2 = dp[j];
        }
      }
    }
    return min_1;
  }
};

int main(int argc, char const *argv[]) { return 0; }