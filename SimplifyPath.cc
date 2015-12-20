#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string simplifyPath(string path) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<string> stack;
    assert(path[0] == '/');
    int i = 0;
    while (i < path.size()) {
      while (path[i] == '/' && i < path.size()) i++;  // skip the begining
                                                      // '////'
      if (i == path.size()) break;
      int start = i;
      while (path[i] != '/' && i < path.size()) i++;  // decide the end boundary
      int end = i - 1;
      string element = path.substr(start, end - start + 1);
      if (element == "..") {
        if (stack.size() > 0) stack.pop_back();
      } else if (element != ".")
        stack.push_back(element);
    }
    if (stack.size() == 0) return "/";
    string simpPath;
    for (int i = 0; i < stack.size(); i++) simpPath += "/" + stack[i];
    return simpPath;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}