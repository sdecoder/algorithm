#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>
#include <unordered_map>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ret;
    stack<TreeNode *> s;
    TreeNode *p = root;

    do {
      while (p != NULL) {
        s.push(p);
        p = p->left;
      }

      if (!s.empty()) {
        p = s.top();
        s.pop();

        ret.push_back(p->val);

        p = p->right;
      }
    } while (!s.empty() || p != NULL);

    return ret;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}