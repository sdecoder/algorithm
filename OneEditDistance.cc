#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include <sstream>
#include <string>


#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>


bool isOneDifL(string s, string t) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == t[i]) continue;
    return s.substr(i) == t.substr(i + 1);
  }
  return true;  // 说明前面的都相等只有最后一个不匹配
}
bool isSameLen(string s, string t) {
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != t[i]) cnt++;
  }
  return cnt == 1;
}
bool isOneEditDistance(string s, string t) {
  if (abs(s.size() - t.size()) > 1) return false;
  if (s.size() == t.size())
    return isSameLen(s, t);
  else if (s.size() < t.size())
    return isOneDifL(s, t);
  else
    return isOneDifL(t, s);
}

bool isOneEditDistance2(string s, string t) {
  if (s.length() > t.length()) {
    swap(s, t);
  }
  if (t.length() - s.length() > 1) {
    return false;
  }
  bool have = false;
  for (int i = 0, j = 0; i < s.length(); ++i, ++j) {
    if (s[i] != t[j]) {
      if (have) {
        return false;
      }
      have = true;
      if (s.length() < t.length()) {
        --i;
      }
    }
  }
  return (have) || (s.length() < t.length());
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}