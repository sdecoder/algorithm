#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>

#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <unordered_map>
using namespace std; 

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int, int> tool;
        tool[0] = -1;
        int sum = 0, maxi = 0;
        for(int e = 0; e < size; ++e)
        {
            sum += nums[e];
            int finder = sum-k;
            if(tool.find(finder) != tool.end())
            {
                int preIndex = tool[finder];
                maxi = maxi<e-preIndex?e-preIndex:maxi;
            }
            if(tool.find(sum) == tool.end())
                tool[sum] = e;
        }
        return maxi;
    }
};




int main(int argc, char const *argv[])
{
  Solution s;
  return 0;
}