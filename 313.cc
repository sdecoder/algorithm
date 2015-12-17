#include <stdio.h>

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    ++n;
    int ugly_number[n];
    ugly_number[0] = 1;
    priority_queue<int, vector<int>, std::greater<int> > pq;
    // priority_queue<int> pq;
    pq.push( ugly_number[0] );

    for (int i = 1; i < n; ++i)
    {
      int temp = pq.top(); pq.pop();
      for (int dx = 0; dx < primes.size(); ++dx) {
        int reg = temp * primes[dx];
        pq.push(reg);
      }
    }



    return 0;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  std::vector<int> input;
  input.push_back(2);
  input.push_back(7);
  input.push_back(13);
  input.push_back(19);

  const int n = 12;
  const int result = s.nthSuperUglyNumber(12, input);
  cout << "[dbg] result is " << result << endl;
  return 0;
}
