#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {

      int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };  
      string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };  
      stringstream result; 
      for (int i = 0; i < sizeof(values)/sizeof(int); i++) {  
            while (num >= values[i]) {  
                num -= values[i];  
                result << (numerals[i]);  
            }  
        }  
        return result.str(); 
      /*  StringBuilder result = new StringBuilder();  
         */
        
    }
};

int main(int argc, char const *argv[])
{
  Solution sol; 
  cout << sol.intToRoman(3999) << endl; 
  return 0;
}