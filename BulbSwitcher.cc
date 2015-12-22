#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
 public:
  int bulbSwitch(int n) { return (int)sqrt(n); }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  cout << sol.bulbSwitch(3) << endl;
  cout << sol.bulbSwitch(50) << endl;
  cout << sol.bulbSwitch(100) << endl;
  return 0;
}