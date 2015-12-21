#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  static string removeDuplicateLetters(string s) {
    string strResult;
    while (!s.empty()) {
      std::vector<int> chCnt(26, 0);
      for (auto ch : s) {
        chCnt[ch - 'a']++;
      }

      int minChIdx = 0;
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] < s[minChIdx]) {
          minChIdx = i;
        }

        chCnt[s[i] - 'a']--;
        if (chCnt[s[i] - 'a'] == 0) {
          break;
        }
      }
      strResult.push_back(s[minChIdx]);
      char minCh = s[minChIdx];
      s = s.substr(minChIdx + 1);
      removeCh(s, minCh);
    }
    return strResult;
  }

  static void removeCh(string& s, char ch) {
    int i = 0, j = 0;
    for (; j < s.size(); ++j) {
      if (s[j] != ch) {
        s[i] = s[j];
        i++;
      }
    }
    s.erase(s.begin() + i, s.end());
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}