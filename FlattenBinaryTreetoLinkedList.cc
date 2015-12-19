
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  void flatten(TreeNode *root) {
    if (root == NULL) return;
    while (root) {
      if (root->left) {
        TreeNode *pre = root->left;
        while (pre->right) pre = pre->right;
        pre->right = root->right;
        root->right = root->left;
        root->left = NULL;
      }
      root = root->right;
    }
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}