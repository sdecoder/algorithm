#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>

#include <stack>

using namespace std;
class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> parens;
    queue<string> candidates;
    unordered_set<string> visited;
    candidates.push(s);
    visited.insert(s);
    bool found = false;
    while (!candidates.empty()) {
      string now = candidates.front();
      candidates.pop();
      if (isValid(now)) {
        parens.push_back(now);
        found = true;
      }
      if (!found) {
        int n = now.length();
        for (int i = 0; i < n; i++) {
          if (now[i] == '(' || now[i] == ')') {
            string next = now.substr(0, i) + now.substr(i + 1);
            if (visited.find(next) == visited.end()) {
              candidates.push(next);
              visited.insert(next);
            }
          }
        }
      }
    }
    return parens;
  }

 private:
  bool isValid(string& s) {
    int c = 0, n = s.length();
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') c++;
      if (s[i] == ')' && !c--) return false;
    }
    return !c;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}