
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  vector<bool> *dp;
  vector<string> mystring;
  vector<string> result;
  vector<string> wordBreak(string s, unordered_set<string> &dict) {
    dp = new vector<bool>[s.size()];
    for (int i = 0; i < s.size(); i++) {
      for (int j = i; j < s.size(); j++) {
        dp[i].push_back(isMatch(s.substr(i, j - i + 1), dict));
      }
    }

    output(s.size() - 1, s);
    return result;
  }

  void output(int i, string s) {
    if (i == -1) {
      string str;
      for (int i = mystring.size() - 1; i >= 0; i--) {
        str += mystring[i];
        if (i != 0) {
          str.push_back(' ');
        }
      }
      result.push_back(str);
    } else {
      for (int k = 0; k <= i; k++) {
        if (dp[k][i - k]) {
          mystring.push_back(s.substr(k, i - k + 1));
          output(k - 1, s);
          mystring.pop_back();
        }
      }
    }
  }

  bool isMatch(string str, unordered_set<string> &dict) {
    unordered_set<string>::const_iterator got = dict.find(str);
    if (got != dict.end()) {
      return true;
    } else {
      return false;
    }
  }
};

int main(int argc, char const *argv[]) { return 0; }