
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#include <sstream>
#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>


using namespace std;

class Solution {
 public:
  vector<vector<string> > groupStrings(vector<string>& strings) {
    unordered_map<string, vector<string> > d;
    for (auto i : strings) {
      string s = "";
      for (auto j : i) {
        s += to_string(((j - i[0]) + 26) % 26) + " ";
      }
      if (d.find(s) != d.end()) {
        d[s].push_back(i);
      } else {
        vector<string> v;
        v.push_back(i);
        d.insert(pair<string, vector<string> >(s, v));
      }
    }

    vector<vector<string> > result;
    for (auto i = d.begin(); i != d.end(); i++) {
      sort(i->second.begin(), i->second.end());
      result.push_back(i->second);
    }
    return result;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}