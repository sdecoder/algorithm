#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<int> result;
    result.resize(rowIndex + 2);
    for (int i = 0; i < rowIndex + 2; i++)
      result[i] = 0;
    result[1] = 1;
    for (int i = 0; i < rowIndex; i++) {
      for (int j = rowIndex + 1; j > 0; j--) {
        result[j] = result[j - 1] + result[j];
      }
    }
    result.erase(result.begin());
    return result;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}