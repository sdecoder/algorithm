#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>

using namespace std;
class Solution {
public:
  bool isAnagram(string s, string t) {

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s == t)
      return true;
    return false;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}