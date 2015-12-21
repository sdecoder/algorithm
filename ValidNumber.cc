#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;
/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should
gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your
function signature accepts a const char * argument, please click the reload
button  to reset your code definition.


*/

namespace solution2 {
class Solution {
 public:
  bool isNumber(string s) {
    int size = s.size();
    if (size == 0) {
      return false;
    }  // if
    // 前导0
    int start = 0;
    while (s[start] == ' ') {
      ++start;
    }  // while
    // 后导0
    int end = size - 1;
    while (s[end] == ' ') {
      --end;
    }  // while
    bool hasNum = false, hasPoint = false, hasE = false;
    for (int i = start; i <= end; ++i) {
      if (s[i] == '.') {
        // 如果前面已经有了'.' 或者 'e'
        if (hasPoint || hasE) {
          return false;
        }  // if
        hasPoint = true;
      }  // if
      else if (s[i] == 'e') {
        // 如果前面已经有了'e' 或者 没数字
        if (hasE || !hasNum) {
          return false;
        }  // if
        hasE = true;
      }  // else
      else if (s[i] < '0' || s[i] > '9') {
        // +2
        if (i == start && (s[i] == '+' || s[i] == '-')) {
          continue;
        }  // if
        // 1e-2
        else if ((i != 0 && s[i - 1] == 'e') && (s[i] == '+' || s[i] == '-')) {
          continue;
        } else {
          return false;
        }  // else
      }  // else
      else {
        hasNum = true;
      }  // else
    }  // for
    // 最后有效位不能是'e+-'
    if (s[end] == 'e' || s[end] == '+' || s[end] == '-') {
      return false;
    }  // if
    // '.'
    if (!hasNum && hasPoint) {
      return false;
    }  // if
    // 全是空格
    if (end == -1) {
      return false;
    }  // if
    return true;
  }
};
}

class Solution {
 public:
  bool isNumber(const char *s) {
    enum InputType {
      INVALID,    // 0
      SPACE,      // 1
      SIGN,       // 2
      DIGIT,      // 3
      DOT,        // 4
      EXPONENT,   // 5
      NUM_INPUTS  // 6
    };

    int transitionTable[][NUM_INPUTS] = {
        -1, 0,  3,  1,  2,  -1,  // next states for state 0
        -1, 8,  -1, 1,  4,  5,   // next states for state 1
        -1, -1, -1, 4,  -1, -1,  // next states for state 2
        -1, -1, -1, 1,  2,  -1,  // next states for state 3
        -1, 8,  -1, 4,  -1, 5,   // next states for state 4
        -1, -1, 6,  7,  -1, -1,  // next states for state 5
        -1, -1, -1, 7,  -1, -1,  // next states for state 6
        -1, 8,  -1, 7,  -1, -1,  // next states for state 7
        -1, 8,  -1, -1, -1, -1,  // next states for state 8
    };

    int state = 0;
    while (*s != '\0') {
      InputType inputType = INVALID;
      if (isspace(*s))
        inputType = SPACE;
      else if (*s == '+' || *s == '-')
        inputType = SIGN;
      else if (isdigit(*s))
        inputType = DIGIT;
      else if (*s == '.')
        inputType = DOT;
      else if (*s == 'e' || *s == 'E')
        inputType = EXPONENT;

      state = transitionTable[state][inputType];

      if (state == -1)
        return false;
      else
        ++s;
    }

    return state == 1 || state == 4 || state == 7 || state == 8;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}