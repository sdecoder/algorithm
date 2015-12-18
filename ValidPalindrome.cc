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
  bool is_alpha_num(char ch) {
    if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') ||
        (ch >= 'A' && ch <= 'Z'))
      return true;
    return false;
  }
  bool isPalindrome(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int left = 0;
    int right = s.size() - 1;
    bool flag = true;
    while (left < right) {
      if (!is_alpha_num((s[left]))) {
        ++left;
        continue;
      }
      if (s[left] >= 'a' && s[left] <= 'z')
        s[left] = 'A' + s[left] - 'a';
      if (!is_alpha_num((s[right]))) {
        --right;
        continue;
      }
      if (s[right] >= 'a' && s[right] <= 'z')
        s[right] = 'A' + s[right] - 'a';
      if (s[left] != s[right]) {
        flag = false;
        break;
      }
      ++left;
      --right;
    }
    return flag;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}