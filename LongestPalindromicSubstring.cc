#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

namespace s2 {
class Solution {
 public:
  string longestPalindrome(string &s) {
    char anSt[1000][1000] = {0};
    int nInpLen = s.length();
    int nLongestPalBegin = 0;
    int nLongestPalLen = 0;

    for (int i = 0; i < nInpLen; ++i) {
      anSt[i][i] = 1;
    }

    for (int nLen = 2; nLen <= nInpLen; ++nLen) {
      for (int i = 0; i < nInpLen - nLen + 1; ++i) {
        int j = i + nLen - 1;
        if (s.at(i) == s.at(j) && nLen == 2) {
          anSt[i][j] = 1;
          nLongestPalBegin = i;
          nLongestPalLen = nLen;
        } else if (s.at(i) == s.at(j) && anSt[i + 1][j - 1] == 1) {
          anSt[i][j] = 1;
          nLongestPalBegin = i;
          nLongestPalLen = nLen;
        }
      }
    }
    if (nInpLen >= 2)
      return s.substr(nLongestPalBegin, nLongestPalLen);
    else if (nInpLen == 1)
      return s;
  }
};
}

class Solution {
 public:
  string preProcess(string s) {
    int n = s.length();
    if (n == 0) return "^$";
    string ret = "^";
    for (int i = 0; i < n; i++) ret += "#" + s.substr(i, 1);

    ret += "#$";
    return ret;
  }

  string longestPalindrome(string s) {
    string T = preProcess(s);
    int n = T.length();
    int *P = new int[n];
    int C = 0, R = 0;
    for (int i = 1; i < n - 1; i++) {
      int i_mirror = 2 * C - i;  // equals to i' = C - (i-C)

      P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;

      // Attempt to expand palindrome centered at i
      while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) P[i]++;

      // If palindrome centered at i expand past R,
      // adjust center based on expanded palindrome.
      if (i + P[i] > R) {
        C = i;
        R = i + P[i];
      }
    }

    // Find the maximum element in P.
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
      if (P[i] > maxLen) {
        maxLen = P[i];
        centerIndex = i;
      }
    }
    delete[] P;

    return s.substr((centerIndex - 1 - maxLen) / 2, maxLen);
  }
};

int main(int argc, char const *argv[]) { return 0; }