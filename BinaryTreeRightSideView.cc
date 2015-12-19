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
 public:
  std::vector<int> result;
  void rightViewUtil(struct TreeNode *root, int level, int *max_level) {
    // Base Case
    if (root == NULL) return;

    // If this is the last Node of its level
    if (*max_level < level) {
      // printf("%d\t", root->data);
      result.push_back(root->val);
      *max_level = level;
    }

    // Recur for right subtree first, then left subtree
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
  }

  vector<int> rightSideView(TreeNode *root) {
    int max_level = 0;
    result.clear();
    rightViewUtil(root, 1, &max_level);
    return result;
  }
};

int main(int argc, char const *argv[]) { 
  Solution sol;
  return 0;
   }