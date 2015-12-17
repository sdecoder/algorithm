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
  TreeNode *invertTree(TreeNode *root) {
    invert_tree_util(root);
    return root;
  }

  void invert_tree_util(TreeNode *root) {
    if (root == NULL)
      return;
    swap(root->left, root->right);
    invert_tree_util(root->left);
    invert_tree_util(root->right);
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}