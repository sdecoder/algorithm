#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
  string unguarded_convert(const string &say) {
    stringstream ss;
    int count = 0;
    char last = say[0];

    for (size_t i = 0; i <= say.size(); ++i) {
      if (say[i] == last) {
        ++count;
      } else {
        ss << count << last;
        count = 1;
        last = say[i];
      }
    }

    return ss.str();
  }

  string countAndSay(int n) {
    if (n <= 0)
      return string();

    string say = "1";

    for (int i = 1; i < n; ++i) {
      say = unguarded_convert(say);
    }

    return say;
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  return 0;
}