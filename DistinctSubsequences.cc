#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>

#include <stack>

using namespace std;

class Solution {
 public:
  int numDistinct(string S, string T) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    int lens = S.length(), lent = T.length();
    if (lent == 0)
      return 1;
    else if (lens == 0)
      return 0;
    int dp[lens + 1][lent + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= lens; i++) dp[i][0] = 1;
    for (int i = 1; i <= lens; i++) {
      for (int j = 1; j <= lent; j++) {
        if (S[i - 1] == T[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j];
      }
    }
    return dp[lens][lent];
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}