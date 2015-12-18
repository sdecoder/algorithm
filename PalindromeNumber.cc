#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return 0;
    int n = 0, temp = x, big = 1, small = 1;
    while (temp != 0) {
      n++;
      temp /= 10;
      if (temp)
        big *= 10;
    }

    for (int i = 0; i < n / 2; ++i) {
      if ((x / big) % 10 != (x / small) % 10)
        return 0;
      big /= 10;
      small *= 10;
    }
    return 1;
  }
};
int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}