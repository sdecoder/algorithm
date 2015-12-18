
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

int intabs(int para) {
  if (para >= 0)
    return para;
  return -para;
}

int bigger_start(int x, int y) {
  if (x >= y)
    return x;
  return y;
}
int smaller_end(int x, int y) {
  if (x <= y)
    return x;
  return y;
}

int intersect(int line_start1, int line_end1, int line_start2, int line_end2) {
  /* printf("line_start1: %d\n", line_start1);
    printf("line_end1: %d\n", line_end1);
    printf("line_start2: %d\n", line_start2);
    printf("line_end2: %d\n", line_end2);*/

  if (line_start1 <= line_start2) {
    if (line_end1 < line_start2)
      return 0;
    else
      return 1;
  } else {
    if (line_end2 < line_start1)
      return 0;
    else
      return 1;
  }
}

class Solution {
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int xone_start = A;
    int xone_end = C;
    int xtwo_start = E;
    int xtwo_end = G;

    int yone_start = B;
    int yone_end = D;

    int ytwo_start = F;
    int ytwo_end = H;

    int rec1 = intabs(xone_start - xone_end) * intabs(yone_start - yone_end);
    int rec2 = intabs(xtwo_start - xtwo_end) * intabs(ytwo_start - ytwo_end);
    // printf("rec1_area: %d\n", rec1);
    // printf("rec2_area: %d\n", rec2);

    if (intersect(xone_start, xone_end, xtwo_start, xtwo_end) &&
        intersect(yone_start, yone_end, ytwo_start, ytwo_end)) {

      // printf("two rectangles intersects\n" );
      int width = intabs(bigger_start(xone_start, xtwo_start) -
                         smaller_end(xone_end, xtwo_end));
      int height = intabs(bigger_start(yone_start, ytwo_start) -
                          smaller_end(yone_end, ytwo_end));
      // printf("intersected area: %d\n", width * height);

      return rec1 + rec2 - width * height;
    }

    return rec1 + rec2;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}