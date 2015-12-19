#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int sqrt(int x) {
    if (x == 0) return 0;
    double last = 0;
    double res = 1;
    while (res != last) {
      last = res;
      res = (res + x / res) / 2;
    }
    return int(res);
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}