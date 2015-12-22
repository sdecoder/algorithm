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

// Forward declaration of the knows API. 2 
bool knows(int a, int b){
  return true; 
}

class Solution {
 public:
  int findCelebrity(int n) {
    int l = 0, r = n - 1;
    while (l < r) {
      if (knows(l, r))
        ++l;
      else
        --r;
    }
    for (int i = 0; i < n; ++i)
      if (i != l) {
        if (knows(l, i) || !knows(i, l)) return -1;
      }
    return l;
  }
};

int main(int argc, char const *argv[]) { return 0; }