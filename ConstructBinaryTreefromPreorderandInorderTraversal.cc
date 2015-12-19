
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 private:
  TreeNode *build(vector<int> &preorder, vector<int> &inorder, int pl, int pr,
                  int il, int ir) {
    TreeNode *root;
    if (pl > pr || il > ir) {
      root = NULL;
    } else {
      root = new TreeNode(preorder[pl]);
      int i;
      for (i = il; i <= ir && preorder[pl] != inorder[i]; i++)
        ;
      root->left = build(preorder, inorder, pl + 1, pl + i - il, il, i - 1);
      root->right = build(preorder, inorder, pl + i - il + 1, pr, i + 1, ir);
    }
    return root;
  }

 public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    return build(preorder, inorder, 0, preorder.size() - 1, 0,
                 inorder.size() - 1);
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}