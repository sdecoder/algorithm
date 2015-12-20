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
class Solution {
 public:
  int getMax(vector<int> num) {
    int m = INT_MIN;
    for (int i = 0; i < num.size(); i++) {
      m = max(m, num[i]);
    }
    return m;
  }

  void countSort(vector<int> &num, int nd) {
    int n = num.size();
    vector<int> output(n, 0);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++) {
      count[(num[i] / nd) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
      count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
      output[count[(num[i] / nd) % 10] - 1] = num[i];
      count[(num[i] / nd) % 10]--;
    }

    for (int i = 0; i < n; i++) {
      num[i] = output[i];
    }
  }

  void radixsort(vector<int> &num) {
    int max_n = getMax(num);
    for (int nd = 1; max_n / nd > 0; nd *= 10) {
      countSort(num, nd);
    }
  }

  int maximumGap(vector<int> &num) {
    if (num.size() < 2) {
      return 0;
    }
    radixsort(num);
    int res = abs(num[1] - num[0]);
    for (int i = 2; i < num.size(); i++) {
      if (num[i] - num[i - 1] > res) {
        res = abs(num[i] - num[i - 1]);
      }
    }
    return res;
  }
};

int main(int argc, char const *argv[]) { return 0; }