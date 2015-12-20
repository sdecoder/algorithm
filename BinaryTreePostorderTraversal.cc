#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

#include <sstream>
#include <iostream>
#include <vector>
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
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> rs;
    if (!root) return rs;
    stack<TreeNode *> stk;
    stk.push(root);
    while (!stk.empty()) {
      TreeNode *t = stk.top();
      stk.pop();
      rs.push_back(t->val);
      if (t->left) stk.push(t->left);
      if (t->right) stk.push(t->right);
    }
    reverse(rs.begin(), rs.end());
    return rs;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}