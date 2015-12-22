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
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*

The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it
returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that
readsn characters from the file.

Note:
The read function may be called multiple times.

需要用Queue保存之前多读的character。每次读时，先看Queue里的够不够，如果不够，先读到够为止。

*/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
 public:
  /**
   * @param buf Destination buffer
   * @param n   Maximum number of characters to read
   * @return    The number of characters read
   */
  int read(char *buf, int n) {
    if (n == 0) return 0;
    int total = 0;
    while (this->buffer.size() < n && !this->endOfFile) {
      char *temp = new char[4];
      int r = read4(temp);
      if (r < 4) this->endOfFile = true;
      for (int i = 0; i < r; i++) this->buffer.push(temp[i]);
    }

    int l = min((int)this->buffer.size(), n);
    for (int i = 0; i < l; i++) {
      buf[i] = this->buffer.front();
      this->buffer.pop();
      total++;
    }
    return total;
  }

 private:
  queue<char> buffer;
  bool endOfFile = false;
};

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}

