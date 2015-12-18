#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <limits.h>


using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int minDepth(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (root == NULL)
      return 0;
    int lmin = minDepth(root->left);
    int rmin = minDepth(root->right);
    if (lmin == 0 && rmin == 0)
      return 1;
    if (lmin == 0) {
      lmin = INT_MAX;
    }
    if (rmin == 0) {
      rmin = INT_MAX;
    }
    return min(lmin, rmin) + 1;
  }
};

int main(int argc, char const *argv[]) { return 0; }