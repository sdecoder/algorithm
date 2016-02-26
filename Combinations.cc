
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

class Solution{
private:
  std::vector<std::vector<int> > ret;
  std::vector<int> a;
 public:
    void solve(int dep, int maxDep, int n, int start){
      if( dep == maxDep ){
        ret.push_back(a);
        return; 
      }

      for(int i = start; i <= n; ++i){
        a[dep] = i; 
        solve(dep + 1, maxDep, n, i+1);
      }
    }

    std::vector<std::vector<int> > combine(int n, int k ){
      a.resize(k);
      ret.clear(); 
      solve(0, k, n, 1);
      return ret;
    }

};


int main(int argc, char const *argv[])
{
  Solution s; 
  return 0;
}