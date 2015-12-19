#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
          int i, j;
          int *dp = new int[n + 1];
 
        if (n == 0) return 1;
 
        dp[0] = dp[1] = 1;
 
        for (i = 2; i <= n; i++) {
            dp[i] = 0;
            for (j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
 
        return dp[n];
        
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}