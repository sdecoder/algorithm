#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
  string convertToTitle(int n) {
    if (n <= 0)
      return "";
    stringstream ss;
    while (n) {
      char reg = 'A' + (n - 1) % 26;
      ss << reg;
      n = (n - 1) / 26;
    }
    string result = ss.str();
    reverse(result.begin(), result.end());
    return result;
  }
};

int main(int argc, char const *argv[]) {

  Solution s;
  cout << s.convertToTitle(28) << endl;
  return 0;
}