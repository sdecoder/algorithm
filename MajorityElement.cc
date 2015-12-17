#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &num) {
    int counter = 0;
    int answer = 0;
    for (int i = 0; i < num.size(); ++i) {
      if (counter == 0) {
        answer = num[i];
        counter++;

      } else {
        if (num[i] != answer) {
          counter--;
        } else
          counter++;
      }
    }

    return answer;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}