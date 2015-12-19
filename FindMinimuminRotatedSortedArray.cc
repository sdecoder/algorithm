#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

#include <sstream>
#include <iostream>
#include <vector>


using namespace std;


class Solution {

int min_(int a, int b){
  return a <= b ? a : b; 
}


public:
    int findMin(vector<int>& num) {
    if( num.size() == 0) return 0;  
    int l = 0;  
    int r = num.size()-1;  
    int min = num[0];  
    while(l<r-1)  
    {  
        int m = (l+r)/2;  
        if(num[l]<num[m])  
        {  
            min =  min_(num[l],min);  
            l = m+1;  
        }  
        else if(num[l]>num[m])  
        {  
            min =  min_(num[m],min);  
            r = m-1;  
        }  
        else  
        {  
            l++;  
        }  
    }  
    min =  min_(num[r],min);  
    min =  min_(num[l],min);  
    return min;  
  }  
};

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}