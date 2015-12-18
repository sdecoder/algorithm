#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
  int removeDuplicates(int A[], int n) {
    if (n == 0)
      return 0;
    int index = 0;
    for (int i = 0; i < n; i++) {
      if (A[index] == A[i]) {
        continue;
      }
      index++;
      A[index] = A[i];
    }
    return index + 1;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}