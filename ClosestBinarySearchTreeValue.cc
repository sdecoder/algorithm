#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

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


double double_abs(double val){
  return val > 0 ? val : -val;
}

class Solution {
 public:
  int closestValue(TreeNode* root, double target) {
    if (!root) return INT_MAX;
    if (!(root->left) && !(root->right)) return root->val;
    int left = closestValue(root->left, target);
    int right = closestValue(root->right, target);
    double td = double_abs(root->val - target);
    double ld = double_abs(left - target);
    double rd = double_abs(right - target);
    if (td < ld)
      return td < rd ? root->val : right;
    else
      return ld < rd ? left : right;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}