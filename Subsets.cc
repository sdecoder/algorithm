
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
  bool flag[100000];

 public:
  void run(int depth, int max_depth, vector<int> &S,
           vector<vector<int> > &ans) {
    if (depth == max_depth) {
      // output the solution
      std::vector<int> tmp_vec;
      for (int i = 0; i < max_depth; ++i) {
        /* code */
        if (flag[i]) {
          tmp_vec.push_back(S[i]);
          cout << S[i] << " ";
        }
      }
      ans.push_back(tmp_vec);
      cout << endl;
      return;
    }

    flag[depth] = 0;
    run(depth + 1, max_depth, S, ans);
    flag[depth] = 1;
    run(depth + 1, max_depth, S, ans);
  }

  vector<vector<int> > subsets(vector<int> &S) {
    sort(S.begin(), S.end());
    memset(flag, 0, sizeof(flag));
    vector<vector<int> > ans;
    run(0, S.size(), S, ans);
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}