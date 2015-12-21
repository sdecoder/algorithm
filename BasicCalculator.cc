#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#include <string>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <cctype>


using namespace std;
 
class Solution {
  // "1 + 1"
 public:
  int calculate(string s) {
    if (s.size() == 0) return 0;

    stack<int> stack;
    int res = 0;
    int sign = 1;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      if (isdigit(c)) {
        int cur = c - '0';
        while (i + 1 < s.size() && isdigit(s[i + 1])) {
          cur = 10 * cur + s[++i] - '0';
        }
        res += sign * cur;
      } else if (c == '-') {
        sign = -1;
      } else if (c == '+') {
        sign = 1;
      } else if (c == '(') {
        stack.push(res);
        res = 0;
        stack.push(sign);
        sign = 1;
      } else if (c == ')') {
        const int reg1 = stack.top(); stack.pop(); 
        const int reg2 = stack.top(); stack.pop();
        res = reg1 * res + reg2;
        sign = 1;
      }
    }
    return res;
  }
};

int main(int argc, char const *argv[])
{
  /* code */
  Solution sol; 
  cout << sol.calculate("1 + 1") << endl; 
  cout << sol.calculate(" 2-1 + 2 ") << endl; 
  cout << sol.calculate("(1+(4+5+2)-3)+(6+8)") << endl; 

  return 0;
}