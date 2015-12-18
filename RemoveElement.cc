#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
  int removeElement(int A[], int n, int elem) {
    int i, j;
    for (int i = 0; i < n; i++) {
      if (A[i] == elem) {
        for (j = i; j < n - 1; j++)
          A[j] = A[j + 1];
        n--;
        i--;
      }
    }
    return n;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}