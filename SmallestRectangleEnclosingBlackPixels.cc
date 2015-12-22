
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
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
[LeetCode] Smallest Rectangle Enclosing Black Pixels

This post shares very detailed explanation of how to use binary search to find
the boundaries of the smallest rectangle that encloses the black pixels.

The code is as follows.*/

class Solution {
 public:
  int minArea(vector<vector<char>>& image, int x, int y) {
    int m = image.size(), n = image[0].size();
    int l = search(image, 0, x, 0, n, true, true);
    int r = search(image, x + 1, m, 0, n, false, true);
    int u = search(image, 0, y, l, r, true, false);
    int d = search(image, y + 1, n, l, r, false, false);
    return (r - l) * (d - u);
  }

 private:
  bool white(vector<vector<char>>& image, int mid, int k, int row) {
    return (row ? image[mid][k] : image[k][mid]) == '0';
  }
  int search(vector<vector<char>>& image, int b, int e, int mini, int maxi,
             bool first, bool row) {
    while (b != e) {
      int mid = (b + e) / 2, k = mini;
      while (k < maxi && white(image, mid, k, row)) k++;
      if (k < maxi == first)
        e = mid;
      else
        b = mid + 1;
    }
    return b;
  }
};

int main(int argc, char const* argv[]) { return 0; }