#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>


using namespace std;

class Solution {  
public:  
    int uniquePaths(int m, int n) {  
        vector<int> v(n, 1);  
        for(int i=1; i<m; ++i){  
            for(int j=1; j<n; ++j){  
                v[j]+=v[j-1];  
            }  
        }  
        return v[n-1];  
    }  
};  


int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}