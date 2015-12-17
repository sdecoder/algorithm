#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
  set<int> int_set;
  bool containsDuplicate(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      int temp = nums[i];
      if (int_set.find(temp) != int_set.end())
        return true;
      int_set.insert(temp);
    }
    return false;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}