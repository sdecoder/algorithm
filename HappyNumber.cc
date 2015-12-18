#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
  set<int> S;
  bool isHappy(int n) {

    int t;
    long long sum = 0;
    while (n != 0) {
      t = n % 10;
      n = n / 10;
      sum += t * t;
    }
    if (sum == 1) {
      return 1;
    } else {
      if (S.find(sum) != S.end()) { // 如果在集合里面
        return 0;
      }
      S.insert(sum);
      return isHappy(sum);
    }
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}