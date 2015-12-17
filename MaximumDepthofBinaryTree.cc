#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (root == NULL)
      return 0;

    int res = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      ++res;
      for (int i = 0, n = q.size(); i < n; ++i) {
        TreeNode *p = q.front();
        q.pop();

        if (p->left != NULL)
          q.push(p->left);
        if (p->right != NULL)
          q.push(p->right);
      }
    }

    return res;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}