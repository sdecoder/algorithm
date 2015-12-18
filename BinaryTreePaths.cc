#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
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
  vector<string> result;
  vector<int> element;

  void binaryTreePathsHelper(TreeNode *root) {

    element.push_back(root->val);
    if (root->left == NULL && root->right == NULL) {
      stringstream ss;
      int i;
      for (i = 0; i < element.size() - 1; ++i) {
        ss << element[i] << "->";
      }
      ss << element[i];
      result.push_back(ss.str());
      return;
    }

    if (root->left == NULL) {
      binaryTreePathsHelper(root->right);
      element.pop_back();
    } else if (root->right == NULL) {
      binaryTreePathsHelper(root->left);
      element.pop_back();
    } else {
      binaryTreePathsHelper(root->left);
      element.pop_back();
      binaryTreePathsHelper(root->right);
      element.pop_back();
    }
  }

  vector<string> binaryTreePaths(TreeNode *root) {
    result.clear();
    element.clear();
    if (root == NULL)
      return result;
    binaryTreePathsHelper(root);
    return result;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}