#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  // static declare and definition with local scope
 public:
  void letterCombinations_aux(int step, string& path, vector<string>& ans,
                              const string& digits) {
    // pay attention to this kind of statement
    const static string strT[10] = {"",    "",    "abc",  "def", "ghi",
                                    "jkl", "mno", "qprs", "tuv", "wxyz"};
    if (step == digits.size()) {
      ans.push_back(path);
      return;
    }
    for (int i = 0; i < strT[digits[step] - '0'].size(); ++i) {
      path.push_back(strT[digits[step] - '0'][i]);
      letterCombinations_aux(step + 1, path, ans, digits);
      path.pop_back();
    }
  }
  vector<string> letterCombinations(string digits) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    string path;
    vector<string> ans;
    int step = 0;
    letterCombinations_aux(step, path, ans, digits);
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}