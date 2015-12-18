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

class MinStack {
public:
  void push(int x) {
    st.push(x);
    if (stm.empty() || stm.top() >= x)
      stm.push(x);
  }

  void pop() {
    int top = st.top();
    st.pop();
    if (top <= stm.top())
      stm.pop();
  }

  int top() { return st.top(); }

  int getMin() { return stm.top(); }

private:
  stack<int> st;
  stack<int> stm;
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}