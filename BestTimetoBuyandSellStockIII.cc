/*
Best Time to Buy and Sell Stock III My Submissions Question
Total Accepted: 47556 Total Submissions: 189524 Difficulty: Hard
Say you have an array for which the ith element is the price of a given stock on
day i.

Design an algorithm to find the maximum profit. You may complete at most two
transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell
the stock before you buy again).

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int profit = 0, n = prices.size();
    if (n == 0) {
      return 0;
    }
    int l[n], r[n];
    memset(l, 0, sizeof(int) * n);
    memset(r, 0, sizeof(int) * n);
    int min = prices[0];
    for (int i = 1; i < n; i++) {
      l[i] = prices[i] - min > l[i - 1] ? prices[i] - min : l[i - 1];
      min = prices[i] < min ? prices[i] : min;
    }
    int max = prices[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      r[i] = max - prices[i] > r[i + 1] ? max - prices[i] : r[i + 1];
      max = prices[i] > max ? prices[i] : max;
    }
    for (int i = 0; i < n; i++) {
      profit = l[i] + r[i] > profit ? l[i] + r[i] : profit;
    }
    return profit;
  }
};

int main(int argc, char const *argv[]) { return 0; }