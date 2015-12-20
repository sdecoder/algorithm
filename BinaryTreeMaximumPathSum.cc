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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  int maxPathSum(TreeNode *root) {
    int result = INT_MIN;
    maxpath(root, result);
    return result;
  }

  inline int max(int left, int right) { return left > right ? left : right; }

  int maxpath(struct TreeNode *root, int &result) {
    if (root == NULL) return 0;
    int left = maxpath(root->left, result);
    int right = maxpath(root->right, result);
    int arc = root->val + left + right;
    int single = max(root->val, max(left, right) + root->val);
    result = max(max(arc, single), result);
    return single;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}