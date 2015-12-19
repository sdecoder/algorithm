#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>


using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
 public:
  stack<TreeNode *> s;
  BSTIterator(TreeNode *root) { pushLeft(root); }

  /** @return whether we have a next smallest number */
  bool hasNext() { return !s.empty(); }

  /** @return the next smallest number */
  int next() {
    TreeNode *top = s.top();
    s.pop();
    pushLeft(top->right);
    return top->val;
  }

  void pushLeft(TreeNode *root) {
    if (root != NULL) {
      s.push(root);
      TreeNode *cur = root;
      while (cur->left) {
        s.push(cur->left);
        cur = cur->left;
      }
    }
  }
};



int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}