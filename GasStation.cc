#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int sum = 0;
    int total = 0;
    int j = -1;
    for (int i = 0; i < gas.size(); ++i) {
      sum += gas[i] - cost[i];
      total += gas[i] - cost[i];
      if (sum < 0) {
        j = i;
        sum = 0;
      }
    }
    if (total < 0)
      return -1;
    else
      return j + 1;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}