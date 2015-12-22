
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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode *upsideDownBinaryTree(TreeNode *root) {
    TreeNode *cur = root, *p = nullptr, *pr = nullptr;
    while (cur) {
      // Rotate
      auto left = cur->left;  // store
      cur->left = pr;
      pr = cur->right;  // move on
      cur->right = p;

      // Move on left-wards
      p = cur;
      cur = left;
    }
    return p;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}