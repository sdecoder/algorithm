#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

#include <sstream>
#include <iostream>
#include <vector>


using namespace std; 
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() <= 1)
            return 0;
        int low = prices[0];
        int maxp = 0;
        for(int i = 1; i < prices.size(); ++i) {
            int profit = prices[i] - low;
            if(maxp < profit) maxp = profit;
            if(low > prices[i]) low = prices[i];
        }
        return maxp;
    }
};


int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}