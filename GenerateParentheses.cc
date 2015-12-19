#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    void internalGenerateParenthesis(vector<string> & result,
            string &s,
            int n,
            int left_num,
            int right_num) {
        if ((n == left_num) && (n == right_num)) {
            result.push_back(s);
        }
        
        if (left_num < n) {
            s.push_back('(');
            internalGenerateParenthesis(result, s, n, left_num + 1, right_num);
            s.pop_back();
        }
        
        if (right_num < left_num) {
            s.push_back(')');
            internalGenerateParenthesis(result, s, n, left_num, right_num + 1);
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        
        internalGenerateParenthesis(result, s, n, 0, 0);
        
        return result;
    }
};

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}