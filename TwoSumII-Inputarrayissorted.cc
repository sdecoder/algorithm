
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
  vector<int> ans;
  int left = 1, right = numbers.size();
  long long tmpSum = 0;

  while (left < right) {
    tmpSum = (long long)numbers[left - 1] + (long long)numbers[right - 1];
    if (tmpSum == target) {
      ans.push_back(left);
      ans.push_back(right);
      return ans;
    } else if (tmpSum > target) {
      right--;
    } else {
      left++;
    }
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}