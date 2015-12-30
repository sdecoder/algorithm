
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (auto coin : coins) {
      for (int i = coin; i <= amount; ++i) {
        if (dp[i - coin] != INT_MAX) {
          dp[i] = min(dp[i], dp[i - coin] + 1);
        }
      }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> coins;
  coins.push_back(2);
  const int answer = s.coinChange(coins, 3);
  cout << "[dbg] the final answer: " << answer << endl;
  return 0;
}