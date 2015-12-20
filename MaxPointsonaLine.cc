/*149. Max Points on a Line My Submissions Question
Total Accepted: 50067 Total Submissions: 366352 Difficulty: Hard
Given n points on a 2D plane, find the maximum number of points that lie on the
same straight line.

Subscribe to see which companies asked this question*/

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
#include <set>
#include <unordered_map>

using namespace std;

struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

class Solution {
 public:
  int maxPoints(vector<Point> &points) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    unordered_map<float, int> mp;
    int maxNum = 0;
    for (int i = 0; i < points.size(); i++) {
      mp.clear();
      mp[INT_MIN] = 0;
      int duplicate = 1;
      for (int j = 0; j < points.size(); j++) {
        if (j == i) continue;
        if (points[i].x == points[j].x && points[i].y == points[j].y) {
          duplicate++;
          continue;
        }
        float k = points[i].x == points[j].x
                      ? INT_MAX
                      : (float)(points[j].y - points[i].y) /
                            (points[j].x - points[i].x);
        mp[k]++;
      }
      unordered_map<float, int>::iterator it = mp.begin();
      for (; it != mp.end(); it++)
        if (it->second + duplicate > maxNum) maxNum = it->second + duplicate;
    }
    return maxNum;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}