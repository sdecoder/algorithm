

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>
#include <set>
#include <map>
#include <algorithm>

#include <unordered_map>
#include <unordered_set>

using namespace std;
/*
Given an input string, reverse the string word by word. A word is defined as a
sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are
always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?
*/

class Solution {
 public:
  void reverseWords(string s) {
    if (s.size() == 0) return;
    reverse(s.begin(), s.end());
    int last = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        reverse(s.begin() + last, s.begin() + (i - 1));
        last = i + 1;
      }
    }
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}