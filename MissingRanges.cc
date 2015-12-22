
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

class Solution {
 public:
  vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
    vector<string> ret;
    if (n == 0) return ret;
    string str;
    if (lower < A[0]) {
      if (lower < A[0] - 1)
        str =
            to_string((long long)lower) + "->" + to_string((long long)A[0] - 1);
      else
        // lower == A[0]-1
        str = to_string((long long)lower);
      ret.push_back(str);
    }
    for (int i = 1; i < n; i++) {
      if (A[i] - A[i - 1] < 2) continue;

      if (A[i] - A[i - 1] > 2)
        str = to_string((long long)A[i - 1] + 1) + "->" +
              to_string((long long)A[i] - 1);
      else
        // A[i] - A[i-1] == 2
        str = to_string((long long)A[i - 1] + 1);
      ret.push_back(str);
    }
    if (A[n - 1] < upper) {
      if (A[n - 1] < upper - 1)
        str = to_string((long long)A[n - 1] + 1) + "->" +
              to_string((long long)upper);
      else
        // upper == A[n-1]+1
        str = to_string((long long)upper);
      ret.push_back(str);
    }
    return ret;
  }
};

int main(int argc, char const *argv[]) {  return 0; }