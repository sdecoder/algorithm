#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  stack<TreeNode *> stk;
  int kthSmallest(TreeNode *root, int k) {
    int ret = -1;
    if (!root) return ret;
    TreeNode *obj = k_smallest_element_inorder(root, k);
    return obj->val;
  }

  TreeNode *k_smallest_element_inorder(TreeNode *root, int k) {
    TreeNode *pCrawl = root;
    /* move to left extremen (minimum) */
    while (pCrawl) {
      stk.push(pCrawl);
      pCrawl = pCrawl->left;
    }

    /* pop off stack and process each node */
    while (true) {
      if (stk.empty()) break;
      pCrawl = stk.top();
      stk.pop();
      /* each pop operation emits one element
        in the order
     */
      if (!--k) {
        /* loop testing */
        // st->stackIndex = 0;
        break;
      }

      /* there is right subtree */
      if (pCrawl->right) {
        /* push the left subtree of right subtree */
        pCrawl = pCrawl->right;
        while (pCrawl) {
          stk.push(pCrawl);
          pCrawl = pCrawl->left;
        }

        /* pop off stack and repeat */
      }
    }

    /* node having k-th element or NULL node */
    return pCrawl;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}