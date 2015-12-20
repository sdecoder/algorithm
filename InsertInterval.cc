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
#include <list>
#include <stack>

using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
 public:
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<Interval> result;
    vector<Interval>::iterator it;
    bool flag = true;
    for (it = intervals.begin(); it != intervals.end(); it++) {
      if (it->end < newInterval.start) {
        result.push_back(*it);
        continue;
      }
      if (it->start > newInterval.end) {
        if (flag) {
          result.push_back(newInterval);
          flag = false;
        }

        result.push_back(*it);
        continue;
      }
      newInterval.start =
          it->start < newInterval.start ? it->start : newInterval.start;
      newInterval.end = it->end > newInterval.end ? it->end : newInterval.end;
    }
    if (flag) {
      result.push_back(newInterval);
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}