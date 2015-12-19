
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
 private:
  vector<vector<int> > ret;
  vector<int> a;

 public:
  void solve(int dep, int maxDep, int target, vector<int> &cand) {
    if (target < 0) return;

    if (dep == maxDep) {
      if (target == 0) {
        vector<int> res;
        for (int i = 0; i < maxDep; i++)
          for (int j = 0; j < a[i]; j++) res.push_back(cand[i]);
        ret.push_back(res);
      }
      return;
    }

    for (int i = 0; i <= target / cand[dep]; i++) {
      a[dep] = i;
      solve(dep + 1, maxDep, target - cand[dep] * i, cand);
    }
  }

  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    sort(candidates.begin(), candidates.end());

    a.resize(candidates.size());
    ret.clear();
    if (candidates.size() == 0) return ret;

    solve(0, candidates.size(), target, candidates);

    return ret;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}