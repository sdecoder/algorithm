
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// http://www.hrwhisper.me/leetcode-super-ugly-number/

class Node {
 public:
  int index;
  int val;
  int prime;

  Node(int index, int val, int prime) {
    this->val = val;
    this->index = index;
    this->prime = prime;
  }

  // int compareTo(Node x) { return this.val > x.val ? 1 : -1; }
};

class Comparator {
 public:
  bool operator()(const Node& lhs, const Node& rhs) {
    return (lhs.val > rhs.val);
  }
};

class Solution {
 public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    int* ugly_number = new int[n];
    ugly_number[0] = 1;
    priority_queue<Node, std::vector<Node>, Comparator> q;
    for (int i = 0; i < primes.size(); i++)
      q.push(Node(0, primes[i], primes[i]));
    for (int i = 1; i < n; i++) {
      Node cur = q.top();
      ugly_number[i] = cur.val;
      do {
        cur = q.top();
        q.pop();
        cur.val = ugly_number[++cur.index] * cur.prime;
        q.push(cur);
      } while (!q.empty() && q.top().val == ugly_number[i]);
    }
    return ugly_number[n - 1];
  }
};

int main(int argc, char const* argv[]) { 
  Solution sol; 
  vector<int> primes; 
  primes.push_back(2);
  primes.push_back(7);
  primes.push_back(13);
  primes.push_back(19); 

  for (int i = 1; i <= 12; ++i)
  {
    cout << "[dbg] index: " << i << " value: " << sol.nthSuperUglyNumber(i , primes) << endl;
  }

  return 0; 
}