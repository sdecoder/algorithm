#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void reverseWords(string &s) {
    reverse(s.begin(), s.end());
    cout << "[dbg] reversed s: " << s << endl;
    for (int i = 0; i < s.size(); )
    {
      while(s[i++] == ' ' && i < s.size()); 
      const int start = --i; 
      while(s[i++] != ' ' && i < s.size());
      const int end = i - 1; 
      cout << "[dbg] start: " <<   start << " end: " << end <<  endl;
      if( end < s.size() - 1)
        reverse(s.begin() + start, s.begin() + end);  
      else 
        reverse(s.begin() + start, s.begin() + end +1);
    }

    
    cout << "[dbg] result: " << s << endl; 
  }
};

int main(int argc, char const *argv[]) {
  Solution sol; 
  string para = "     the      sky     is      blue    ";
  sol.reverseWords( para ); 
  return 0;
}