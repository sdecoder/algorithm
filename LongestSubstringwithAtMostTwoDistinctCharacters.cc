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

class Solution {
 public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    if (s == "")
      return 0;
    else if (s.size() <= 2)
      return s.size();

    // slip window [begin, end]
    // initial the window with two different chars
    int size = s.size();
    int begin = 0;
    int end = 1;
    while (end < size && s[end] == s[begin]) end++;
    // to here, end == size or s[end] != s[begin]
    if (end == size) return size;  // all chars are the same

    char inWindow[2] = {s[begin], s[end]};
    map<char, int> m;  // char->count map
    m[s[begin]] = end - begin;  //[begin,end) are all s[begin]
    m[s[end]] = 1;
    int longest = end - begin + 1;
    end++;
    while (end < size) {
      m[s[end]]++;
      if (s[end] == inWindow[0] || s[end] == inWindow[1])
        // in window, extend end
        longest = max(longest, end - begin + 1);
      else {  // not in window, shrink begin
        // remove a char from window
        while (m[inWindow[0]] != 0 && m[inWindow[1]] != 0) {
          m[s[begin]]--;
          begin++;
        }
        // to here, either m[inWindow[0]] == 0 or m[inWindow[1]] == 0
        if (m[inWindow[0]] == 0)
          inWindow[0] = s[end];
        else
          inWindow[1] = s[end];
      }
      end++;
    }
    return longest;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}