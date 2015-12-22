#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
 public:
  int minMeetingRooms(vector<Interval>& intervals) {
    vector<pair<int, int>> schedule;
    for (auto interval : intervals) {
      schedule.push_back({interval.start, 1});
      schedule.push_back({interval.end, -1});
    }
    sort(schedule.begin(), schedule.end());
    int cnt = 0, res = 0;
    for (auto s : schedule) {
      if (s.second == 1)
        ++cnt;
      else
        --cnt;
      res = max(res, cnt);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}