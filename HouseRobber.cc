#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
  int rob(vector<int> &num) {
    if (num.empty()) {
      return 0;
    } // if
    int size = num.size();
    vector<int> dp(size, 0);

    dp[0] = num[0];
    dp[1] = max(num[0], num[1]);
    for (int i = 2; i < size; ++i) {
      dp[i] = max(dp[i - 1], dp[i - 2] + num[i]);
    } // for
    return dp[size - 1];
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}