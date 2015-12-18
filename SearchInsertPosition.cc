#include <iostream>
#include <vector>
using namespace std;

class Solution {
  int searchInsert(std::vector<int> &v, int target, int start, int end) {
    int mid = start + ((end - start) >> 1);
    if (target == v[mid])
      return mid;
    else if (target < v[mid])
      return start < mid ? searchInsert(v, target, start, mid - 1) : start;
    else
      return end > mid ? searchInsert(v, target, mid + 1, end) : end + 1;
  }

public:
  int searchInsert(vector<int> &nums, int target) {
    if (nums.size() == 0)
      return 0;
    ;
    return searchInsert(nums, target, 0, nums.size() - 1);
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}