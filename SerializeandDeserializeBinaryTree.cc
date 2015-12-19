#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) { val = x; }
};


class Codec {
 private:
  void _serialize(TreeNode* root, ostringstream& sout) {
    if (root == NULL) {
      sout << "# ";
      return;
    }
    sout << root->val << " ";
    _serialize(root->left, sout);
    _serialize(root->right, sout);
  }
  void _deserialize(TreeNode*& root, istringstream& sin) {
    int val;
    string tmp;
    if (sin >> tmp && tmp != "#") {
      val = stoi(tmp);
    } else {
      return;
    }
    root = new TreeNode(val);
    _deserialize(root->left, sin);
    _deserialize(root->right, sin);
  }

 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    ostringstream sout;
    _serialize(root, sout);
    return sout.str();
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream sin(data);
    TreeNode* root = NULL;
    _deserialize(root, sin);
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}