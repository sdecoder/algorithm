
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
  vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
    vector<int> answer;
    const int start = max(k - nums2.size(), 0);
    const int end = min(nums1.size(), k);
    for (int i = start; i <= end; i++) {
      vector<int> res1;
      res1.clear();
      vector<int> res2;
      res2.clear();

      solve(nums1, i, res1);
      solve(nums2, k - i, res2);
      vector<int> res;
      res.clear();
      int pos1 = 0, pos2 = 0, tpos = 0;

      while (pos1 < res1.size() || pos2 < res2.size()) {
        const int para =
            compare(res1, pos1, res2, pos2) ? res1[pos1++] : res2[pos2++];
        res.push_back(para);
      }

      if (!compare(ans, 0, res, 0)) {
        answer.clear();
        for (int i = 0; i < k; ++i) {
          answer.push_back(res[i]);
        }
      }
    }

    return answer;
  }

  bool compare(vector<int> &nums1, int start1, vector<int> &nums2, int start2) {
    for (; start1 < nums1.size() && start2 < nums2.size(); start1++, start2++) {
      if (nums1[start1] > nums2[start2])
        return true;
      if (nums1[start1] < nums2[start2])
        return false;
    }
    return start1 != nums1.size();
  }

  void solve(vector<int> &nums, int k, vector<int> &res) {

    int len = 0;
    for (int i = 0; i < nums.size(); i++) {
      while (len > 0 && len + nums.size() - i > k && res[len - 1] < nums[i]) {
        len--;
      }
      if (len < k)
        res.push_back(nums[i]);
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}