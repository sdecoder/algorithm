#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
 public:
  int evalRPN(vector<string> &tokens) {
    int dx = 0;
    stack<int> _stack;
    for (dx = 0; dx < tokens.size(); ++dx) {
      string _para = tokens[dx];

      if (!isdigit(_para.c_str()[0])) {
        char op = _para.c_str()[0];
        if (op == '-') {
          if (_para.length() != 1) {
            // cout<< "[dbg] push value: " << atoi(_para.c_str())<< endl;
            _stack.push(atoi(_para.c_str()));
            continue;
          }
        }
        int _op1 = _stack.top();
        _stack.pop();
        int _op2 = _stack.top();
        _stack.pop();
        if (op == '+')
          _stack.push(_op1 + _op2);
        else if (op == '-')
          _stack.push(_op2 - _op1);
        else if (op == '*')
          _stack.push(_op1 * _op2);
        else if (op == '/')
          _stack.push((int)(_op2 / _op1));

      } else
        _stack.push(atoi(_para.c_str()));
    }

    return _stack.top();
  }
};

int main(int argc, char const *argv[]) { return 0; }