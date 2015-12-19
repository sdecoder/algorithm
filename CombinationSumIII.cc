#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int> > result;
  vector<int> solution;
  void dfs(int cur, int k, int start, int value) {
    if (cur == k && value == 0) {
    
      result.push_back(solution);
      return;
    } else if (cur == k)
      return;

    for (int i = start; i < 10; i++) {
      if (value >= i) {
        solution.push_back(i);
        dfs(cur + 1, k, i + 1, value - i);
        solution.pop_back();
      }
    }
  }

  vector<vector<int> > combinationSum3(int k, int n) {
    if (n > 9 * k) return result;
    result.clear();
    solution.clear();
    dfs(0, k, 1, n);
    return result;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}