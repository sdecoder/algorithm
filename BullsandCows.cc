#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>

using namespace std; 

class Solution {
public:
    string getHint(string secret, string guess) {
      
      int a_number = 0; 
      int xcounter[100];
      int ycounter[100];
      memset(xcounter, 0, 100 * sizeof(int));
      memset(ycounter, 0, 100 * sizeof(int));
      for(int i = 0; i < secret.size(); i++){
        if(secret[i] == guess[i]) a_number++;
        xcounter[secret[i] - '0'] ++;
        ycounter[guess[i] - '0'] ++;
      }
      
      int b_number = 0; 
      for(int i = 0; i < 10; i++){
        b_number += min(xcounter[i], ycounter[i]);
      }
      
      b_number = b_number - a_number;
      stringstream ss;
      ss << a_number << "A" << b_number << "B"; 

      
      return ss.str();
  
    }
};

int main(){
	
    Solution s; 
    string result = s.getHint("1807", "7810");
    cout<< result <<  endl;
    return 0;
  
}