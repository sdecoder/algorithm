
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    int f1 = 1, f2 = 2, f3;
    if (n == 1)
      return f1;
    if (n == 2)
      return f2;
    for (int i = 2; i < n; i++) {
      f3 = f1 + f2;
      f1 = f2;
      f2 = f3;
    }
    return f3;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}