#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <memory.h>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
      if(n == 1 ) return true;
      if(n < 3) return false;
      const int pow_ = ceil(log(n) / log(3));
      cout << pow_ << endl;
      const int result = pow(3, pow_);
      cout << result << endl;
      return n == result;
    }
};


int main(int argc, char const *argv[])
{
  Solution sol;

  cout << sol.isPowerOfThree(243) << endl;
  return 0;
}