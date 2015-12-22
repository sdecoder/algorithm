
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
You are playing the following Flip Game with your friend: Given a string that
contains only these two characters: + and -, you and your friend take turns to
flip twoconsecutive "++" into "--". The game ends when a person can no longer
make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

For example, given s = "++++", return true. The starting player can guarantee a
win by flipping the middle "++" to become "+--+".

Follow up:
Derive your algorithm's runtime complexity.

*/

class Solution {
 public:
  vector<string> generatePossibleNextMoves(string s) {
    vector<string> moves;
    int n = s.length();
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == '+' && s[i + 1] == '+') {
        s[i] = s[i + 1] = '-';
        moves.push_back(s);
        s[i] = s[i + 1] = '+';
      }
    }
    return moves;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}