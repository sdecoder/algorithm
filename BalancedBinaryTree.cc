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
  bool isBalanced(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (root == NULL)
      return true;
    int val = GetBalance(root);
    if (val == -1)
      return false;
    return true;
  }
  int GetBalance(TreeNode *node) {
    if (node == NULL)
      return 0;
    int left = GetBalance(node->left);
    if (left == -1)
      return -1;
    int right = GetBalance(node->right);
    if (right == -1)
      return -1;
    if (left - right > 1 || right - left > 1)
      return -1;
    return left > right ? left + 1 : right + 1;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}