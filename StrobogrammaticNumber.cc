#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

/*
Problem Description:

A strobogrammatic number is a number that looks the same when rotated 180
degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is
represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.

The following is the C++ implementation of the suggested solution using a
look-up table (implemented as an unordered_map). It takes 0 ms. But, I wonder,
are there any real applications of strobogrammatic numbers?

*/

class Solution {
 public:
  bool isStrobogrammatic(string num) {
    make_lut();
    int n = num.length();
    for (int l = 0, r = n - 1; l <= r; l++, r--)
      if (lut.find(num[l]) == lut.end() || lut[num[l]] != num[r]) return false;
    return true;
  }

 private:
  unordered_map<char, char> lut;
  void make_lut(void) {
    lut['0'] = '0';
    lut['1'] = '1';
    lut['6'] = '9';
    lut['8'] = '8';
    lut['9'] = '6';
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}