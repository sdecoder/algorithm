
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,
             / \
  5
           / \   \
  5   5
return 4.*/

class TreeNode {
 public:
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) { val = x; }
};

class Solution {
 public:
  int countUnivalSubtrees(TreeNode* root) {
    if (root == NULL) return 0;
    vector<int> sum;
    sum.push_back(0);
    helper(root, sum);
    return sum[0];
  }

  bool helper(TreeNode* root, std::vector<int>& sum) {
    if (root == NULL) return true;
    bool left = helper(root->left, sum);
    bool right = helper(root->right, sum);
    if (left && right && (root->left == NULL || root->val == root->left->val) &&
        (root->right == NULL || root->val == root->right->val)) {
      sum[0] = sum[0] + 1;
      return true;
    }
    return false;
  }
};

int main(int argc, char const* argv[]) { return 0; }