#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void dfs(vector<vector<int> > &ans, vector<int> &s, vector<int> &tmp,
           int start) {
    ans.push_back(tmp);

    for (int i = start; i < s.size(); ++i) {
      if (i != start && s[i] == s[i - 1])
        continue;  // select only once in every layer
      tmp.push_back(s[i]);  // select
      dfs(ans, s, tmp, i + 1);  // do recusive
      tmp.pop_back();  // delete
    }
  }
  vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int> > ans;
    if (S.size() <= 0) return ans;
    vector<int> tmp;
    sort(S.begin(), S.end());  // sort
    dfs(ans, S, tmp, 0);
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}