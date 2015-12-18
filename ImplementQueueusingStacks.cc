#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>



using namespace std;

class Queue {
public:
  stack<int> stack1;
  stack<int> stack2;
  // Push element x to the back of queue.

  void push(int x) { stack1.push(x); }

  // Removes the element from in front of queue.
  void pop(void) {
    int x;
    if (stack1.empty() && stack2.empty()) {
      // ign, do nothing;
      return;
    }
    if (stack2.empty()) {
      while (!stack1.empty()) {
        x = stack1.top();
        stack1.pop();
        stack2.push(x);
      }
    }

    // x = stack2.top();
    stack2.pop();
    // return x;
  }

  // Get the front element.
  int peek(void) {
    int result = 0;
    if (stack1.empty() && stack2.empty())
      return result;

    int x;
    if (stack2.empty()) {
      while (!stack1.empty()) {
        x = stack1.top();
        stack1.pop();
        stack2.push(x);
      }
    }

    x = stack2.top();
    return x;
  }

  // Return whether the queue is empty.
  bool empty(void) {
    if (stack1.empty() && stack2.empty())
      return true;
    else
      return false;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}