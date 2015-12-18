
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
  int lengthOfLastWord(const char *s) {
    int len = strlen(s);
    int sum = 0;
    while (s[len - 1] == ' ')
      len--;
    for (int i = len - 1; i >= 0; i--) {
      if (s[i] != ' ')
        sum++;
      else
        break;
    }
    return sum;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}