
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  vector<vector<int> > getFactors(int n) {
    vector<vector<int> > result;
    vector<int> solu;
    if (n <= 1) return result;
    dfs(result, solu, n, n, 2);
    return result;
  }

 private:
  void dfs(vector<vector<int> > &result, vector<int> &solu, int num, int n,
           int idx) {
    if (num == 1) {
      result.push_back(solu);
      return;
    }
    for (int i = idx; i * idx <= n; i++) {
      if (num % i == 0) {
        solu.push_back(i);
        dfs(result, solu, num / i, n, i);
        solu.pop_back();
      }
    }
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}