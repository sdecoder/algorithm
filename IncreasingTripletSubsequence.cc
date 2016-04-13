
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

using namespace std;
 
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int x1 = INT_MAX, x2 = INT_MAX;
        for(int num: nums){
            if(num <= x1) x1 = num;
            else if(num <=x2) x2 = num;
            else return true;
        }
        return false;
    }
};


int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}