#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#include <vector>
#include <iostream>
using namespace std; 

int buffer[1000000];
class NumArray {
public:
    NumArray(vector<int> &nums) {
      if(nums.size() == 0) return; 
      memset(buffer, 0 ,sizeof(buffer));
      buffer[0] = nums[0];
      for (int i = 1; i < nums.size(); ++i)
      {
        buffer[i] = buffer[i-1] + nums[i]; 
      }
    }

    int sumRange(int i, int j) {
      int ans = 0; 
      if(i - 1 <0 ) return buffer[j];
      else return buffer[j] - buffer[i-1]; 

      //return ans;
        
    }
};



// Your NumArray object will be instantiated and called as such:
// NumArray numArray = new NumArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

int main(int argc, char const *argv[])
{

  std::vector<int> input;
  /*Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
*/
  input.push_back(-2);
  input.push_back(0);
  input.push_back(3);
  input.push_back(-5);
  input.push_back(2);
  input.push_back(-1);
  NumArray _num(input);

  cout << _num.sumRange(0, 2) << endl; 
  cout << _num.sumRange(2, 5) << endl;
  cout << _num.sumRange(0, 5) << endl;  

  return 0;
} 