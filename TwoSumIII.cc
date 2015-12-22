#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#include <sstream>
#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <unordered_map>

using namespace std;

/*
Design and implement a TwoSum class. It should support the following operations:
add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false
复制代码
*/

class TwoSum {
  map<int, int> map_;

 public:
  TwoSum() {}

  void add(int x) {
    if (map_.find(x) != map_.end()) {
      map_[x] = map_[x] + 1;
    } else {
      map_[x] = 1;
    }
  }

  bool find(int target) {
    for (auto i : map_) {
      const int x = i.first;
      const int remained = target - x; 
      if( map_.find(remained ) != map_.end()) return true; 

    }
    return false;
  }
};

int main(int argc, char const *argv[]) { 
  TwoSum ts; 
  ts.add(1);
  ts.add(3);
  ts.add(5);

  cout << "find(4): " << ts.find(4) << endl; 
  cout << "find(7): " << ts.find(7) << endl; 

  return 0; }