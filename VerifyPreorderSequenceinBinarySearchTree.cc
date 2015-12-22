
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

namespace solution1 {

bool helper(vector<int>& preorder, int s, int e, int lb, int ub) {
  if (s >= e) return true;
  int r = preorder[s];
  int i = s;
  while (i <= e && preorder[i] <= r) {
    if (preorder[i] < lb || preorder[i] > ub) return false;
    i++;
  }
  return helper(preorder, s + 1, i - 1, lb, r - 1) &&
         helper(preorder, i, e, r + 1, ub);
}

bool verifyPreorder(vector<int>& preorder) {
  int n = preorder.size();
  return helper(preorder, 0, n - 1, INT_MIN, INT_MAX);
}
}

namespace solution2 {
bool verifyPreorder(vector<int>& preorder) {
  int low = INT_MIN;  // lower bound
  stack<int> path;
  for (int p : preorder) {
    if (p < low) {
      return false;
    }
    while (!path.empty() && p > path.top()) {
      low = path.top();
      path.pop();
    }
    path.push(p);
  }
  return true;
}
}

int main(int argc, char const* argv[]) { return 0; }