

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
Given a binary tree, traverse it vertically.

For example:

     5
   /   \
  2     7
 / \   / \
1   3 6   8
     \     \
      4     9


Should return as:

[
  [1],
  [2],
  [5, 3, 6],
  [4, 7],
  [8],
  [9]
]*/

namespace solution1 {
// Solution 1:
//递归前序遍历，直接用vector或者ArrayList来保存结果。
struct TreeNode {
  TreeNode(int v = 0) : val(v) {}
  int val{0};
  TreeNode* left{nullptr};
  TreeNode* right{nullptr};
};

void preorder(vector<vector<int> >& res, TreeNode* node, int col, int& left,
              int& right) {
  if (!node) return;
  if (col < left) {
    left = col;
    res.insert(res.begin(), vector<int>(1, node->val));
  } else if (col > right) {
    right = col;
    res.push_back(vector<int>(1, node->val));
  } else {
    res[col - left].push_back(node->val);
  }
  preorder(res, node->left, col - 1, left, right);
  preorder(res, node->right, col + 1, left, right);
}

vector<vector<int> > vertical_traversal(TreeNode* root) {
  vector<vector<int> > res;
  if (!root) return res;
  int left = 0, right = 0;
  res.push_back(vector<int>());
  preorder(res, root, 0, left, right);
  return res;
}
}

namespace solution2 {
// Solution 2 : 使用HashMap递归前序遍历，然后按照key的大小依次取出值。

void hash_preorder(unordered_map<int, vector<int> >& map, TreeNode* node,
                   int col, int& left, int& right) {
  if (!node) return;
  left = min(col, left);
  right = max(col, right);
  map[col].push_back(node->val);
  hash_preorder(map, node->left, col - 1, left, right);
  hash_preorder(map, node->right, col + 1, left, right);
}

vector<vector<int> > vertical_traversal(TreeNode* root) {
  vector<vector<int> > res;
  if (!root) return res;
  int left = 0, right = 0;
  unordered_map<int, vector<int> > map;
  hash_preorder(map, root, 0, left, right);
  for (int i = left; i <= right; i++) res.push_back(map[i]);
  return res;
}
}

namespace solution3 {

/* 但是上面两种方法都不能保证从上往下看的顺序。所以要保证从上到下的顺序的话，需要用BFS即Level
Order的方法来遍历。用pair<int, TreeNode*>来保存index和节点指针。 Cpp代码 收藏代码 */

vector<vector<int> > vertical_traversal(TreeNode* root) {
  vector<vector<int> > res;
  if (!root) return res;
  unordered_map<int, vector<int> > map;
  queue<pair<int, TreeNode*> > queue;
  queue.emplace(0, root);
  int left = 0, right = 0;
  while (!queue.empty()) {
    auto& p = queue.front();
    queue.pop();
    left = min(left, p.first);
    right = max(right, p.first);
    map[p.first].push_back(p.second->val);
    if (p.second->left) queue.emplace(p.first - 1, p.second->left);
    if (p.second->right) queue.emplace(p.first + 1, p.second->right);
    }  
    for(int i=left; i<=right; i++)   
        res.push_back(map[i]);  
    return res;  
}  
 
}


int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}