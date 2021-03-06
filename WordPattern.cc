#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool wordPattern(string pattern, string str) {
    unordered_map<char, string> map_;
    unordered_map<string, char> rmap;
    istringstream iss(str);
    vector<string> tokens{istream_iterator<string>{iss},
                          istream_iterator<string>{}};

    if (pattern == "" && str == "")
      return true;
    if (pattern == "" && str != "")
      return false;
    if (pattern != "" && str == "")
      return false;

    int i;
    for (i = 0; i < tokens.size(); i++) {
      char meta = pattern[i];
      if (map_.find(meta) != map_.end()) {
        string data_ = map_[meta];
        if (data_ != tokens[i])
          return false;
      } else {
        map_[meta] = tokens[i];
      }

      if (rmap.find(tokens[i]) != rmap.end()) {
        char _c = rmap[tokens[i]];
        if (_c != meta)
          return false;
      } else {
        rmap[tokens[i]] = meta;
      }
    }
    if (i < pattern.length())
      return false;
    return true;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}