#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
 private:
  vector<vector<int> > ret;

 public:
  vector<vector<int> > fourSum(vector<int> &num, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    sort(num.begin(), num.end());
    ret.clear();
    for (int i = 0; i < num.size(); i++) {
      if (i > 0 && num[i] == num[i - 1]) continue;

      for (int j = i + 1; j < num.size(); j++) {
        if (j > i + 1 && num[j] == num[j - 1]) continue;

        int k = j + 1;
        int t = num.size() - 1;

        while (k < t) {
          if (k > j + 1 && num[k] == num[k - 1]) {
            k++;
            continue;
          }

          if (t < num.size() - 1 && num[t] == num[t + 1]) {
            t--;
            continue;
          }

          int sum = num[i] + num[j] + num[k] + num[t];

          if (sum == target) {
            vector<int> a;
            a.push_back(num[i]);
            a.push_back(num[j]);
            a.push_back(num[k]);
            a.push_back(num[t]);
            ret.push_back(a);
            k++;
          } else if (sum < target)
            k++;
          else
            t--;
        }
      }
    }

    return ret;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}