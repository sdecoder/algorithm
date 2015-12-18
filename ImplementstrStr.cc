#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>

using namespace std;

class Solution {
public:
  int strStr(char *haystack, char *needle) {
    if (!haystack && !needle)
      return 0;
    if (!haystack)
      return -1;
    if (!needle)
      return 0;

    int n = strlen(haystack);
    int m = strlen(needle);
    for (int i = 0; i <= n - m; i++) {
      int j = 0;
      for (; j < m; j++) {
        if (needle[j] != haystack[j + i])
          break;
      }
      if (j == m)
        return i;
    }
    return -1;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}