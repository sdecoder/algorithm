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
  int sumNumbers(TreeNode *root) {
    int sum = 0, path = 0;
    GenerateSum(root, sum, path);
    return sum;
  }
  void GenerateSum(TreeNode *root, int &sum, int path) {
    if (root == NULL) return;
    path = path * 10 + root->val;
    if (root->left == NULL && root->right == NULL) {
      sum += path;
      return;
    }
    GenerateSum(root->left, sum, path);
    GenerateSum(root->right, sum, path);
  }
};

int main(int argc, char const *argv[]) {
  Solution sol; 
  /* code */
  return 0;
}