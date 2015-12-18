#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB == NULL)
      return NULL;
    ListNode *_cur_a = headA;
    ListNode *_cur_b = headB;

    ListNode *_tail_a = NULL;
    ListNode *_tail_b = NULL;

    while (1) {
      if (_cur_a == NULL)
        _cur_a = headB;
      if (_cur_b == NULL)
        _cur_b = headA;
      if (_cur_a == _cur_b)
        return _cur_a;

      if (_cur_a->next == NULL)
        _tail_a = _cur_a;
      if (_cur_b->next == NULL)
        _tail_b = _cur_b;
      if (_tail_a != NULL && _tail_b != NULL && _tail_a != _tail_b)
        return NULL;
      _cur_a = _cur_a->next;
      _cur_b = _cur_b->next;
    }
  }
};

int main(int argc, char const *argv[]) {
  /* code */

  return 0;
}