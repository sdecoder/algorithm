#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
  vector<vector<int> > generate(int numRows) {
    vector<vector<int> > res;
    if (numRows <= 0)
      return res;

    vector<int> pre;
    pre.push_back(1);
    res.push_back(pre);
    for (int i = 2; i <= numRows; i++) {
      vector<int> cur;
      cur.push_back(1);
      for (int j = 0; j < pre.size() - 1; j++) {
        cur.push_back(pre[j] + pre[j + 1]);
      }
      cur.push_back(1);
      res.push_back(cur);
      pre = cur;
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}