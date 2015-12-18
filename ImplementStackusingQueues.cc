class Stack {
private:
  stack<int> cheat;
  deque<int> A;
  deque<int> B;

public:
  // Push element x onto stack.
  void push(int x) { A.push_back(x); }

  // Removes the element on top of the stack.
  void pop() {
    while (A.size() > 1) {
      B.push_back(A.front());
      A.pop_front();
    }
    A.pop_front();
    while (B.size() != 0) {
      A.push_back(B.front());
      B.pop_front();
    }
  }

  // Get the top element.
  int top() {
    while (A.size() > 1) {
      B.push_back(A.front());
      A.pop_front();
    }

    int tmp = A.front();
    B.push_back(A.front());

    A.pop_front();
    while (B.size() != 0) {
      A.push_back(B.front());
      B.pop_front();
    }
    return tmp;
  }

  // Return whether the stack is empty.
  bool empty() { return A.empty() && B.empty(); }
};