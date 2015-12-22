/*[LeetCode] Flatten 2D Vector

Problem Description:

　　Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =

[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, the order of elements
returned by next should be: [1, 2, 3, 4, 5, 6].

The idea is very simple. We keep two variables row and col for the range of rows
and cols. Specifically, row is the number of rows of vec2d and col is the number
of columns of the current 1d vector in vec2d. We also keep two variables r and c
to point to the current element.

In the constructor, we initialize row and col as above and initialize both r and
c to be 0(pointing to the first element).

In hasNext(), we just need to check whether r and c are still in the range
limited by row andcol.

In next(), we first record the current element, which is returned later. Then we
update the running indexes and possibly the range if the current element is the
last element of the current 1d vector.

A final and important note, since in next(), we record the current element, we
need to guarantee that there is an element. So we implement a helper function
skipEmptyVector() to skip the empty vectors. It is also important to handle the
case that vec2d is empty (in this case, we set col = -1).

The time complexity of hasNext() is obviously O(1) and the time complexity of
next is alsoO(1) in an amortized sense.

The code is as follows.*/

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
namespace solution1 {
class Vector2D {
 public:
  Vector2D(vector<vector<int> >& vec2d) {
    data = vec2d;
    r = c = 0;
    row = vec2d.size();
    col = (row == 0 ? -1 : data[r].size());
    skipEmptyVector();
  }

  int next() {
    int elem = data[r][c];
    if (c == col - 1) {
      r++;
      c = 0;
      col = data[r].size();
    } else
      c++;
    skipEmptyVector();
    return elem;
  }

  bool hasNext() { return col != -1 && (r < row && c < col); }

 private:
  vector<vector<int> > data;
  int row, col, r, c;
  void skipEmptyVector(void) {
    while (!col) {
      r++;
      col = data[r].size();
    }
  }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
// Since we need to copy the vec2d anyway, we can just copy it into a simple
// vector<int>, which makes life much easier :-)
}

namespace solution2 {
class Vector2D {
 public:
  Vector2D(vector<vector<int> >& vec2d) {
    int row = vec2d.size();
    for (int r = 0; r < row; r++) {
      int col = vec2d[r].size();
      for (int c = 0; c < col; c++) data.push_back(vec2d[r][c]);
    }
    idx = 0;
  }

  int next() { return data[idx++]; }

  bool hasNext() { return idx < data.size(); }

 private:
  vector<int> data;
  int idx;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
}

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
 }