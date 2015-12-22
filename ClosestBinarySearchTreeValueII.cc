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
#include <algorithm>

#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
[LeetCode] Closest Binary Search Tree Value II

Problem Description:

Given a non-empty binary search tree and a target value, find k values in the
BST that are closest to the target.

Note:

Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are
closest to the target.


Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime
(where n = total nodes)?

Hint:

Consider implement these two helper functions:
getPredecessor(N), which returns the next smaller node to N.
getSuccessor(N), which returns the next larger node to N.
Try to assume that each node has a parent pointer, it makes the problem much
easier.
Without parent pointer we just need to keep track of the path from the root to
the current node using a stack.
You would need two stacks to track the path in finding predecessor and successor
node separately.
There is a very simple idea to keep a max heap of size k and elements in the
heap are sorted by their absolute difference from target. For the max heap, we
will simply use the default priority_queue. Then we simply traverse the tree and
push all its nodes to the heap while maintaining the size of heap not larger
than k.*/


namespace sol1 {
class Solution {
 public:
  vector<int> closestKValues(TreeNode* root, double target, int k) {
    priority_queue<pair<double, int>> pq;
    closestK(root, pq, target, k);
    vector<int> closest;
    while (!pq.empty()) closest.push_back(pq.top().second), pq.pop();
    return closest;
  }

 private:
  void closestK(TreeNode* node, priority_queue<pair<double, int>>& pq,
                double target, int k) {
    if (!node) return;
    pq.push(make_pair(abs(target - node->val), node->val));
    if (pq.size() > k) pq.pop();
    closestK(node->left, pq, target, k);
    closestK(node->right, pq, target, k);
  }
};
}

namespace sol2 {
class Solution {
 public:
  vector<int> closestKValues(TreeNode* root, double target, int k) {
    vector<int> closest(k);
    stack<int> pre, suc;
    inorder(root, target, false, pre);
    inorder(root, target, true, suc);
    for (int i = 0; i < k; i++) {
      if (pre.empty())
        closest[i] = suc.top(), suc.pop();
      else if (suc.empty())
        closest[i] = pre.top(), pre.pop();
      else if (abs(target - pre.top()) < abs(target - suc.top()))
        closest[i] = pre.top(), pre.pop();
      else
        closest[i] = suc.top(), suc.pop();
    }
    return closest;
  }

 private:
  void inorder(TreeNode* root, double target, bool reversed, stack<int>& s) {
    if (!root) return;
    inorder(reversed ? root->right : root->left, target, reversed, s);
    if ((reversed && root->val <= target) || (!reversed && root->val > target))
      return;
    s.push(root->val);
    inorder(reversed ? root->left : root->right, target, reversed, s);
  }
};
}

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}