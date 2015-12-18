
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
public:
  bool isSymmetricUtil(TreeNode *root1, TreeNode *root2) {
    if (root1 == NULL && root2 == NULL)
      return true;
    if (root1 == NULL && root2 != NULL)
      return false;
    if (root1 != NULL && root2 == NULL)
      return false;
    return root1->val == root2->val &&
           isSymmetricUtil(root1->left, root2->right) &&
           isSymmetricUtil(root1->right, root2->left);
  }
  bool isSymmetric(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (root == NULL)
      return true;
    return isSymmetricUtil(root->left, root->right);
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}