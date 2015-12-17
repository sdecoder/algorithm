#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {

    if (nums.size() == 0)
      return;

    int insertPos = 0;
    for (int num : nums) {
      if (num != 0)
        nums[insertPos++] = num;
    }
    while (insertPos < nums.size()) {
      nums[insertPos++] = 0;
    }
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  vector<int> data;
  data.push_back(0);
  data.push_back(1);
  data.push_back(0);
  data.push_back(3);
  data.push_back(12);
  sol.moveZeroes(data);

  for (int num : data) {
    cout << num << " ";
  }cout << endl;

  return 0;
}