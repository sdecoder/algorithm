#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string rs;
    if (strs.empty()) return rs;
    int len = strs[0].length();
    for (int i = 1; i < strs.size(); i++) {
      int j = 0;
      for (; j < len && j < strs[i].length() && strs[i - 1][j] == strs[i][j];
           j++)
        ;
      len = j;
    }
    return strs[0].substr(0, len);
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}