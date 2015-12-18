#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>

using namespace std;

class Solution {
public:
  int atoi(const char *str) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int flag1 = 0, sign = 1, int_max = 2147483647, int_min = -2147483648;
    double sum = 0, multi = 1;
    int result = 0;
    vector<int> tmp;

    for (int i = 0; str[i] != NULL; i++) {
      if (tmp.size() == 0 && str[i] == ' ')
        continue;
      if (str[i] == '+' && str[i + 1] >= 48 && str[i + 1] <= 57) {
        sign = 1;
        continue;
      }
      if (str[i] == '-' && str[i + 1] >= 48 && str[i + 1] <= 57) {
        sign = 0;
        continue;
      }
      if ((str[i] < 48 || str[i] > 57) && tmp.size() == 0) {
        return 0;
      }
      if ((str[i] < 48 || str[i] > 57) && tmp.size() != 0) {
        break;
      }
      if (str[i] >= 48 && str[i] <= 57) {
        tmp.push_back(str[i] - 48);
      }
    }

    if (tmp.size() == 0) {
      return 0;
    }


    while (tmp.size() != 0) {
      sum += tmp.back() * multi;
      tmp.pop_back();
      multi = multi * 10;
    }
    if (sign == 0)
      sum = sum * -1;
    if (sum > int_max) {
      return int_max;
    }
    if (sum < int_min) {
      return int_min;
    }
    result = sum;
    return result;


  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}