#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
  int titleToNumber(string s) {
    int ans = 0;
    int len = s.size();
    for (int dx = 0; dx < len; dx++) {
      ans = ans * 26 + (s[dx] - 'A' + 1);
    }

    return ans;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}