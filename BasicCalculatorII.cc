#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  stack<int> opstack;
  stack<int> numstack;

  void skip_space(const char* s, int& index) {
    while (s[index] == ' ') index++;
  }

  int get_value(const char* s, int& index) {
    int current_number = 0;
    while (s[index] >= '0' && s[index] <= '9') {
      current_number = current_number * 10 + (s[index] - '0');
      index++;
    }
    return current_number;
  }

 public:
  int calculate(string s) {
    int _strlen = s.size();
    int current_number = 0;
    int current_ops = 0;  // 0 for +, 1 for minus; // 2 for ( , 3 for )
    for (int i = 0; i < _strlen;) {
      if (s[i] == '*') {
        //  cout<<"[dbg] meet multiply here " << endl;
        int opand1 = numstack.top();
        numstack.pop();
        i++;
        skip_space(s.c_str(), i);
        int opand2 = get_value(s.c_str(), i);
        numstack.push(opand1 * opand2);

      } else if (s[i] == '/') {
        int opand1 = numstack.top();
        numstack.pop();
        i++;
        skip_space(s.c_str(), i);
        int opand2 = get_value(s.c_str(), i);
        numstack.push(opand1 / opand2);

      } else if (s[i] == '+') {
        current_ops = 0;
        opstack.push(0);
        i++;

      } else if (s[i] == '-') {
        current_ops = 1;
        opstack.push(1);
        i++;

      } else if (s[i] >= '0' && s[i] <= '9') {
        int number = get_value(s.c_str(), i);
        numstack.push(number);

      } else if (s[i] == ' ') {
        skip_space(s.c_str(), i);
      }
    }

    std::vector<int> numv;
    std::vector<int> opv;
    while (!numstack.empty()) {
      numv.push_back(numstack.top());
      numstack.pop();
    }

    while (!opstack.empty()) {
      opv.push_back(opstack.top());
      opstack.pop();
    }
    reverse(numv.begin(), numv.end());
    reverse(opv.begin(), opv.end());

    int result = numv[0];
    int numv_cur = 1;
    for (int i = 0; i < opv.size(); ++i) {
      int number = numv[numv_cur++];
      // cout<<"current number " << number << endl;
      if (opv[i] == 0) result = result + number;
      if (opv[i] == 1) result = result - number;
    }

    // printf("Eval result: %d\n", numstack.top());
    return result;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}