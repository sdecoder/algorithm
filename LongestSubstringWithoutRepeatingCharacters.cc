/*
Given a string, find the length of the longest substring without repeating
characters. For example, the longest substring without repeating letters for
"abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is
"b", with the length of 1.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int hash[256];
    for (int i = 0; i < 256; i++) hash[i] = -1;
    int start = 0, ans = 0;
    int i;

    for (i = 0; i < s.size(); i++) {
      if (-1 != hash[s[i]]) {
        if (ans < i - start) ans = i - start;
        for (int j = start; j < hash[s[i]]; j++) hash[j] = -1;
        if (hash[s[i]] + 1 > start) start = hash[s[i]] + 1;
      }

      hash[s[i]] = i;
    }

    if (ans < i - start) ans = i - start;

    return ans;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}