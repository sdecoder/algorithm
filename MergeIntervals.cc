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

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

 
class Solution {
 public:
  struct Comp {
    bool operator()(const Interval &a, const Interval &b) {
      return (a.start < b.start);
    }
  } myComp;

  vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> result;
    if (!intervals.size()) {
      return result;
    }

    sort(intervals.begin(), intervals.end(), myComp);
    vector<Interval>::iterator it = intervals.begin();
    result.push_back(*it);
    it++;

    while (it != intervals.end()) {
      if ((*it).start <= result[result.size() - 1].end) {
        int end = result[result.size() - 1].end > (*it).end
                      ? result[result.size() - 1].end
                      : (*it).end;
        Interval newInterval(result[result.size() - 1].start, end);
        result.pop_back();
        result.push_back(newInterval);
        it++;
      } else {
        result.push_back(*it);
        it++;
      }
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}