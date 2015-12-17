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
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == NULL)
      return NULL;
    if (root == p || root == q)
      return root;

    TreeNode *left_lca = lowestCommonAncestor(root->left, p, q);
    TreeNode *right_lca = lowestCommonAncestor(root->right, p, q);

    if (left_lca && right_lca)
      return root;
    return (left_lca != NULL) ? left_lca : right_lca;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}