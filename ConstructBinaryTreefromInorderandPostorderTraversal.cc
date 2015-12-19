#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

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
 public:
  void build(vector<int> &inorder, vector<int> &postorder, TreeNode *&root,
             int in_s, int in_e, int post_s, int post_e) {
    int i;
    root = new TreeNode(postorder[post_e]);
    for (i = in_s; i <= in_e; ++i)
      if (inorder[i] == postorder[post_e]) break;
    int lnodes = i - in_s;  // the No. of nodes of left subtree
    if (i > in_s)  //
      build(inorder, postorder, root->left, in_s, i - 1, post_s,
            post_s + lnodes - 1);
    if (i < in_e)
      build(inorder, postorder, root->right, i + 1, in_e, post_s + lnodes,
            post_e - 1);
  }
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    // Start typing your C/C++ solution below
    TreeNode *root = NULL;
    if (inorder.size() > 0)
      build(inorder, postorder, root, 0, inorder.size() - 1, 0,
            postorder.size() - 1);
    return root;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}