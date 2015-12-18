#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
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
  vector<vector<int> > result;

  void levelTra(TreeNode *root, int level) {
    if (root == NULL)
      return;
    if (level == result.size()) {
      vector<int> v;
      result.push_back(v);
    }
    result[level].push_back(root->val);
    levelTra(root->left, level + 1);
    levelTra(root->right, level + 1);
  }

  vector<vector<int> > levelOrderBottom(TreeNode *root) {
    levelTra(root, 0);
    return vector<vector<int> >(result.rbegin(), result.rend());
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}