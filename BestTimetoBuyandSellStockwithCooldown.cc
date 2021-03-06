#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int result = 0;
    if (prices.size() == 0) return 0;
    int buy[prices.size()];
    int sell[prices.size()];
    memset(buy, 0, sizeof(int) * prices.size());
    memset(sell, 0, sizeof(int) * prices.size());

    buy[0] = -prices[0];
    buy[1] = max(-prices[0], -prices[1]);
    sell[1] = max(0, prices[1] - prices[0]);
    for (int dx = 2; dx < prices.size(); ++dx) {
      buy[dx] = max(sell[dx - 2] - prices[dx], buy[dx - 1]);
      sell[dx] = max(buy[dx - 1] + prices[dx], sell[dx - 1]);
    }

    return max(buy[prices.size() - 1], sell[prices.size() - 1]);
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}