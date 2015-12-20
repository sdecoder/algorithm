/*
Count of Smaller Numbers After Self My Submissions Question
Total Accepted: 1787 Total Submissions: 7251 Difficulty: Hard
You are given an integer array nums and you have to return a new counts array.
The counts array has the property where counts[i] is the number of smaller
elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>

using namespace std;

namespace merge_sort {

struct Node {
  int val;
  int index;
  int cnt;
  Node(int val, int index) : val(val), index(index), cnt(0) {}
  bool operator<=(const Node &node2) const { return val <= node2.val; }
};

class Solution {
 public:
  void combine(vector<Node> &nums, int Lpos, int Lend, int Rend,
               vector<Node> &temp) {
    int Rpos = Lend + 1;
    int Tpos = Lpos;
    int n = Rend - Lpos + 1;
    int t = Rpos;
    while (Lpos <= Lend && Rpos <= Rend) {
      if (nums[Lpos] <= nums[Rpos]) {
        temp[Tpos] = nums[Lpos];
        temp[Tpos].cnt += Rpos - t;
        Tpos++;
        Lpos++;
      } else {
        temp[Tpos++] = nums[Rpos++];
      }
    }

    while (Lpos <= Lend) {
      temp[Tpos] = nums[Lpos];
      temp[Tpos].cnt += Rpos - t;
      Tpos++;
      Lpos++;
    }

    while (Rpos <= Rend) temp[Tpos++] = nums[Rpos++];

    for (int i = 0; i < n; i++, Rend--) nums[Rend] = temp[Rend];
  }

  void merge_sort(vector<Node> &nums, int L, int R, vector<Node> &temp) {
    if (L < R) {
      int m = (L + R) >> 1;
      merge_sort(nums, L, m, temp);
      merge_sort(nums, m + 1, R, temp);
      combine(nums, L, m, R, temp);
    }
  }

  vector<int> countSmaller(vector<int> &nums) {
    vector<Node> mynums;
    vector<Node> temp(nums.size(), Node(0, 0));
    for (int i = 0; i < nums.size(); i++) mynums.push_back(Node(nums[i], i));

    vector<int> ans(nums.size(), 0);
    merge_sort(mynums, 0, nums.size() - 1, temp);

    for (int i = 0; i < nums.size(); i++) ans[mynums[i].index] = mynums[i].cnt;

    return ans;
  }
};
}

namespace segment_tree {
class Solution {
 private:
  typedef vector<int> vec;

 public:
  vec countSmaller(vec &nums) {
    vec ans;
    int n = 0;
    if (!(n = nums.size())) return ans;
    ans.resize(n, 0);
    ret = new P[n + 10];
    for (int i = 1; i <= n; i++) ret[i] = P(nums[i - 1], i);
    sort(ret + 1, ret + n + 1);
    seg = new int[(n + 10) << 2];
    memset(seg, 0, sizeof(int) * ((n + 10) << 2));
    for (int i = 1; i <= n; i++) {
      int v = query(1, 1, n, ret[i].id, n);
      insert(1, 1, n, ret[i].id);
      ans[ret[i].id - 1] = v;
    }
    delete[] seg;
    delete[] ret;
    return ans;
  }

 private:
  struct P {
    int v, id;
    P(int _i_ = 0, int _j_ = 0) : v(_i_), id(_j_) {}
    friend bool operator<(const P &a, const P &b) {
      return a.v == b.v ? a.id < b.id : a.v < b.v;
    }
  } * ret;
  int *seg;
  inline void insert(int root, int l, int r, int p) {
    if (p > r || p < l) return;
    if (p <= l && p >= r) {
      seg[root]++;
      return;
    }
    int mid = (l + r) >> 1;
    insert(root << 1, l, mid, p);
    insert(root << 1 | 1, mid + 1, r, p);
    seg[root] = seg[root << 1] + seg[root << 1 | 1];
  }
  inline int query(int root, int l, int r, int x, int y) {
    if (x > r || y < l) return 0;
    if (x <= l && y >= r) return seg[root];
    int ret = 0;
    int mid = (l + r) >> 1;
    ret += query(root << 1, l, mid, x, y);
    ret += query(root << 1 | 1, mid + 1, r, x, y);
    return ret;
  }
};
}

namespace fenwick_tree{
  
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}