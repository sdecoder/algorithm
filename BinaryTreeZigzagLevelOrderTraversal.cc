#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > result;
    if (root == NULL) return result;

    stack<TreeNode *> stk1, *curstk;
    stack<TreeNode *> stk2, *nextstk, *tmp;
    stk1.push(root);
    curstk = &stk1;
    nextstk = &stk2;
    bool flag = false;
    vector<int> data(0);
    while (!curstk->empty()) {
      data.clear();
      while (!curstk->empty()) {
        root = curstk->top();
        curstk->pop();
        data.push_back(root->val);
        if (flag) {
          if (root->right != NULL) nextstk->push(root->right);
          if (root->left != NULL) nextstk->push(root->left);
        } else {
          if (root->left != NULL) nextstk->push(root->left);
          if (root->right != NULL) nextstk->push(root->right);
        }
      }
      result.push_back(data);
      flag = !flag;
      tmp = curstk;
      curstk = nextstk;
      nextstk = tmp;
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}