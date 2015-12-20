#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>

using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& num) {
    unordered_map<int, int> hashmap;
    vector<int> length(num.size(), 0);
    for (int i = 0; i < num.size(); i++) {
      hashmap[num[i]] = i;
    }
    for (int i = 0; i < num.size(); i++) {
      // skip the node, which already calculate the length
      if (length[i] > 0) continue;
      length[i] = consecutiveLength(num[i], hashmap, length);
    }
    int maxV = INT_MIN;
    for (int i = 0; i < num.size(); i++) {
      maxV = length[i] > maxV ? length[i] : maxV;
    }
    return maxV;
  }
  int consecutiveLength(int num, unordered_map<int, int>& hashmap,
                        vector<int>& length) {
    if (hashmap.find(num) == hashmap.end()) return 0;
    int index = hashmap[num];
    // skip the node, which already calculate the length
    if (length[index] > 0)
      return length[index];
    else {
      // hit each fresh node only once
      length[index] = consecutiveLength(num - 1, hashmap, length) + 1;
      return length[index];
    }
  }
};

namespace solution2 {

int longestConsecutive(vector<int>& num) {
  unordered_set<int> set_;

  for (int i : num) {
    set_.insert(i);
  }
  int max_ = 0;

  for (int i = 0; i < num.size(); i++) {
    if (set_.find(num[i]) != set_.end()) {
      int next = num[i] - 1;  // 找比num[i]小一个的值
      int count = 1;
      set_.erase(num[i]);  // 及时的移除，减少之后的查找时间
      while (set_.find(next) != set_.end()) {
        set_.erase(next);
        next--;
        count++;
      }
      next = num[i] + 1;  // 找比num[i]大一个的值
      while (set_.find(next) != set_.end()) {
        set_.erase(next);
        next++;
        count++;
      }
      max_ = max(max_, count);
    }
  }

  return max_;
}
}

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}