#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class comparator {
 public:
  bool operator()(const string& lhs, const string& rhs) {
    return (lhs + rhs) > (rhs + lhs);
  }
};

class Solution {
 public:
  string largestNumber(vector<int>& num) {
    vector<string> strs;
    for (int i = 0; i < num.size(); ++i) {
      const int value = num[i];
      strs.push_back(to_string(value));
    }
    comparator _compare;
    sort(strs.begin(), strs.end(), _compare);
    string ans = "";

    int i = 0;
    while (i < strs.size() && strs[i++] == "0")
      ;
    for (i--; i < strs.size(); ++i) {
      ans = ans + strs[i];
    }

    return ans == "" ? "0" : ans;
  }
};

int main(int argc, char const* argv[]) {
  std::vector<int> v;
 /* v.push_back(3);
  v.push_back(30);
  v.push_back(34);
  v.push_back(5);
  v.push_back(9);*/
    v.push_back(0);
  v.push_back(0);
  Solution sol;
  cout << sol.largestNumber(v) << endl;
  /* code */
  return 0;
}