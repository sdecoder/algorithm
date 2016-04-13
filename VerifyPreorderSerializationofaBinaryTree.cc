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
  bool isValidSerialization(string preorder) {
    if (preorder.size() == 0)
      return true;
    char s = preorder[0];
    if( preorder.size() >=2 ) preorder = preorder.substr(2);
    else preorder = "";
    cout << "[dbg] current s: " << s << endl;
    cout << "[dbg] preorder after substr: " << preorder << " size: " <<  preorder.size() << endl;
    if (s == '#')
      return true;
    if (preorder.size() == 0 || !isValidSerialization(preorder))
      return false;
    if (preorder.size() == 0 || !isValidSerialization(preorder))
      return false;

    return true;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  Solution s;
  //string input = "9,3,4,#,#,1,#,#,2,#,6,#,#";
  //cout << "[dbg] input: " << input << " result:" << s.isValidSerialization(input) << endl;
  string input = "1,#";
  cout << "[dbg] input: " << input << " result:" << s.isValidSerialization(input) << endl;
  //string input = "9,#,#,1";
  //cout << "[dbg] input: " << input << " result:" << s.isValidSerialization(input) << endl;


  return 0;
}