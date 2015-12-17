#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
  static int charToInt(char c) {
    int data = 0;

    switch (c) {
    case 'I':
      data = 1;
      break;
    case 'V':
      data = 5;
      break;
    case 'X':
      data = 10;
      break;
    case 'L':
      data = 50;
      break;
    case 'C':
      data = 100;
      break;
    case 'D':
      data = 500;
      break;
    case 'M':
      data = 1000;
      break;
    }

    return data;
  }

  static int romanToInt(string s) {
    int i, total, pre, cur;

    total = charToInt(s[0]);

    for (i = 1; i < s.size(); i++) {
      pre = charToInt(s[i - 1]);
      cur = charToInt(s[i]);

      if (cur <= pre) {
        total += cur;
      } else {
        total = total - pre * 2 + cur;
      }
    }

    return total;
  }
};

int main(int argc, char const *argv[])
{
  Solution sol;
  return 0;
}