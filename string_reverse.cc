
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std; 


int main(int argc, char const *argv[])
{
  stringstream _stream;
  _stream << "this a test string"; 
  string _string = _stream.str(); 

  reverse(_string.begin(), _string.end());
  cout << "[dbg] reversed string: " << _string << endl; 

  return 0;
}