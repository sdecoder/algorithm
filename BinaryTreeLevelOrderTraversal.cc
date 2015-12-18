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
  vector<vector<int> > levelOrder(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > output;
    if (!root)
      return output;
    vector<int> oneLine;
    bool hasNextLevel = true;
    int currentLevel = 1;
    while (hasNextLevel) {
      hasNextLevel = false;
      LevelTravel(root, currentLevel, hasNextLevel, oneLine);
      output.push_back(oneLine);
      currentLevel++;
      oneLine.clear();
    }
    return output;
  }
  void LevelTravel(TreeNode *node, int level, bool &hasNextLevel,
                   vector<int> &result) {
    if (!node)
      return;
    if (level == 1) {
      result.push_back(node->val);
      if (node->left || node->right)
        hasNextLevel = true;
      return;
    } else {
      LevelTravel(node->left, level - 1, hasNextLevel, result);
      LevelTravel(node->right, level - 1, hasNextLevel, result);
    }
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}