#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>

using namespace std;
bool isBadVersion(int version);

class Solution {
public:
  /**
   * @param n: An integers.
   * @return: An integer which is the first bad version.
   */
  int firstBadVersion(int n) {
    if (n < 1) {
      return -1;
    }

    int start = 1;
    int end = n;
    int mid;
    while (start + 1 < end) {
      mid = start + (end - start) / 2;
      if (isBadVersion(mid)) {
        end = mid;
      } else {
        start = mid;
      }
    }

    if (isBadVersion(start)) {
      return start;
    } else if (isBadVersion(end)) {
      return end;
    }

    return -1; // find no bad version
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}