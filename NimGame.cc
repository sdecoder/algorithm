#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
  bool canWinNim(int n) { return (n % 4 == 0) ? false : true; }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  cout << sol.canWinNim(100) << endl;
  return 0;
}