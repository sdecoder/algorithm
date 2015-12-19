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
    int singleNumber(int A[], int n) {  
        const size_t INTLEN = sizeof(int) * 8;  
        int bitCount[INTLEN];  
        fill(bitCount, bitCount + INTLEN, 0);  
          
        for(int i = 0; i < n; ++i)  
            for(size_t j = 0; j < INTLEN; ++j)  
                bitCount[j] += ((A[i] & (1 << j)) != 0);  
          
        int single = 0;  
        for(size_t j = 0; j < INTLEN; ++j)  
            if ((bitCount[j] % 3) == 1)  
                single += (1 << j);  
          
        return single;  
    }  
};  



int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}