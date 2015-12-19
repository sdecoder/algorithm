
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>

using namespace std;





#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

class Solution {
public:
     int maxSubArray(int A[], int n) {
       int newsum=A[0];
       int max=A[0];
       for(int i=1;i < n ;i++){
           newsum = MAX(newsum+A[i],A[i]);
           max= MAX(max, newsum);
       }
       return max;
    }
};


int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}