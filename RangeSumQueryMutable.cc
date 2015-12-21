#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>

using namespace std;

namespace seg_tree {
struct SegmentTreeNode {
  int s, e, sum;
  SegmentTreeNode* left;
  SegmentTreeNode* right;
  SegmentTreeNode(int _s, int _e)
      : s(_s), e(_e), sum(0), left(NULL), right(NULL) {}
};

class SegmentTree {
 public:
  SegmentTree(vector<int>& nums) {
    int n = nums.size();
    root = buildST(nums, 0, n - 1);
  }

  void update(int i, int val) { update(root, i, val); }

  int sumRange(int i, int j) { return sumRange(root, i, j); }

 private:
  SegmentTreeNode* root;
  SegmentTreeNode* buildST(vector<int>& nums, int s, int e) {
    if (s > e)
      return NULL;
    else {
      SegmentTreeNode* res = new SegmentTreeNode(s, e);
      if (s == e)
        res->sum = nums[s];
      else {
        int m = s + (e - s) / 2;
        res->left = buildST(nums, s, m);
        res->right = buildST(nums, m + 1, e);
        res->sum = res->left->sum + res->right->sum;
      }
      return res;
    }
  }
  void update(SegmentTreeNode* root, int i, int val) {
    if (root->s == root->e)
      root->sum = val;
    else {
      int m = root->s + (root->e - root->s) / 2;
      if (i <= m)
        update(root->left, i, val);
      else
        update(root->right, i, val);
      root->sum = root->left->sum + root->right->sum;
    }
  }
  int sumRange(SegmentTreeNode* root, int s, int e) {
    if (root->s == s && root->e == e)
      return root->sum;
    else {
      int m = root->s + (root->e - root->s) / 2;
      if (e <= m)
        return sumRange(root->left, s, e);
      else if (s >= m + 1)
        return sumRange(root->right, s, e);
      else
        return sumRange(root->left, s, m) + sumRange(root->right, m + 1, e);
    }
  }
};

class NumArray {
 public:
  NumArray(vector<int>& nums) { st = new SegmentTree(nums); }

  void update(int i, int val) { st->update(i, val); }

  int sumRange(int i, int j) { return st->sumRange(i, j); }

 private:
  SegmentTree* st;
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
}

namespace tree_array {
class NumArray {
 public:
  NumArray(vector<int>& nums) {
    num.resize(nums.size() + 1);
    bit.resize(nums.size() + 1);
    for (int i = 0; i < nums.size(); ++i) {
      update(i, nums[i]);
    }
  }
  void update(int i, int val) {
    int diff = val - num[i + 1];
    for (int j = i + 1; j < num.size(); j += (j & -j)) {
      bit[j] += diff;
    }
    num[i + 1] = val;
  }
  int sumRange(int i, int j) { return getSum(j + 1) - getSum(i); }
  int getSum(int i) {
    int res = 0;
    for (int j = i; j > 0; j -= (j & -j)) {
      res += bit[j];
    }
    return res;
  }

 private:
  vector<int> num;
  vector<int> bit;
};
}

int main(int argc, char const* argv[]) { return 0; }