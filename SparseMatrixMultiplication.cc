
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
[LeetCode] Sparse Matrix Multiplication

Problem Description:

Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
The solution is much more easier than we may have imagined. Take a look at this
solution. But note that it is buggy as pointed out in the first comment (oh, how
could the test cases be so weak)! I have rewritten it as follows.*/

class Solution {
 public:
  vector<vector<int> > multiply(vector<vector<int> >& A, vector<vector<int> >& B) {
    int m = A.size(), n = B.size(), p = B[0].size();
    vector<vector<int> > C(m, vector<int>(p, 0));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (A[i][j])
          for (int k = 0; k < p; k++) C[i][k] += A[i][j] * B[j][k];
    return C;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}