
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int h = 0;
    sort(citations.begin(), citations.end());

    for (int loc = citations.size() - 1;
         loc >= 0 && citations[loc] >= (citations.size() - loc); --loc) {
      h = citations.size() - loc;
    }

    return h;
  }
};

int main(int argc, char const* argv[]) { return 0; }