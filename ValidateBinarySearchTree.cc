/*Validate Binary Search Tree My Submissions Question
Total Accepted: 73384 Total Submissions: 360461 Difficulty: Medium
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's
key.
The right subtree of a node contains only nodes with keys greater than the
node's key.
Both the left and right subtrees must also be binary search trees.
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on
OJ.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems
*/

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

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  bool check(TreeNode *node, int leftVal, int rightVal) {
    if (node == NULL) return true;

    return leftVal < node->val && node->val < rightVal &&
           check(node->left, leftVal, node->val) &&
           check(node->right, node->val, rightVal);
  }

  bool isValidBST(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    return check(root, INT_MIN, INT_MAX);
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}