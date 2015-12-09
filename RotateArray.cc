#include <iostream>
#include <vector>

#include <algorithm>

using namespace std; 


class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    const int len = nums.size(); 
    k = k % len;
    k = len - k;
    std::rotate(nums.begin(),nums.begin()+k,nums.end());

   /*reverse(nums.begin(), nums.begin() + k  ); 
    reverse(nums.begin() + k, nums.begin() + len  ); 
    reverse(nums.begin(), nums.end() ); */
  }
};

int main(int argc, char const *argv[])
{
  Solution s; 
  std::vector<int> v;
  for (int i = 1; i < 8; ++i)
  {
    v.push_back(i);
  }
  s.rotate(v, 3);

  for (int i = 0; i < v.size(); ++i)
  {
    cout << v[i] << " ";
  }cout<< endl;
  return 0;
}