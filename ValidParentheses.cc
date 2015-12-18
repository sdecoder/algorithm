

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    string::iterator it = s.begin();
    while (it != s.end()) {
      switch (*it) {
      case '(':
        st.push('(');
        break;
      case '[':
        st.push('[');
        break;
      case '{':
        st.push('{');
        break;
      case ')':
        if (!st.empty() && st.top() == '(') {
          st.pop();
        } else {
          return false;
        }
        break;
      case ']':
        if (!st.empty() && st.top() == '[') {
          st.pop();
        } else {
          return false;
        }
        break;
      case '}':
        if (!st.empty() && st.top() == '{') {
          st.pop();
        } else {
          return false;
        }
        break;
      default:
        break;
      }
      it++;
    }

    if (st.empty()) {
      return true;
    } else {
      return false;
    }
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}