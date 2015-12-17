#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
  int addDigits(int num) { return (num - 1) % 9 + 1; }
};

int main(int argc, char const *argv[]) {
  Solution s;
  return 0;
}