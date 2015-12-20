
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

using namespace std;

/*
Expression Add Operators My Submissions Question
Total Accepted: 5838 Total Submissions: 27038 Difficulty: Hard
Given a string that contains only digits 0-9 and a target value, return all
possibilities to add binary operators (not unary) +, -, or * between the digits
so they evaluate to the target value.

Examples:
"123", 6 -> ["1+2+3", "1*2*3"]
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []*/

class Solution {
 public:
  vector<string> addOperators(string num, int target) {
    vector<string> res;
    addOperatorsDFS(num, target, 0, 0, "", res);
    return res;
  }
  void addOperatorsDFS(string num, int target, long long diff, long long curNum,
                       string out, vector<string> &res) {
    if (num.size() == 0 && curNum == target) {
      res.push_back(out);
    }
    for (int i = 1; i <= num.size(); ++i) {
      string cur = num.substr(0, i);
      if (cur.size() > 1 && cur[0] == '0') return;
      string next = num.substr(i);
      if (out.size() > 0) {
        addOperatorsDFS(next, target, stoll(cur), curNum + stoll(cur),
                        out + "+" + cur, res);
        addOperatorsDFS(next, target, -stoll(cur), curNum - stoll(cur),
                        out + "-" + cur, res);
        addOperatorsDFS(next, target, diff * stoll(cur),
                        (curNum - diff) + diff * stoll(cur), out + "*" + cur,
                        res);
      } else {
        addOperatorsDFS(next, target, stoll(cur), stoll(cur), cur, res);
      }
    }
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}