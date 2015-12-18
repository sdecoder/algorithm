#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isUgly(int num) {
    if (num <= 0)
      return false;
    while (num % 2 == 0)
      num /= 2;
    while (num % 3 == 0)
      num /= 3;
    while (num % 5 == 0)
      num /= 5;
    return num == 1;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}