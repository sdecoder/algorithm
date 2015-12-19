#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    ListNode *before, *start, *end, *after;
    before = after = start = end = NULL;
    ListNode *ptr = head;
    for (int i = 1; i < m; i++) {
      before = ptr;
      ptr = ptr->next;
    }
    start = end = ptr;
    for (int i = m; i <= n; i++) {
      after = ptr->next;
      ptr->next = end;
      end = ptr;
      ptr = after;
    }
    if (before == NULL) {
      head = end;
    } else {
      before->next = end;
    }
    start->next = after;
    return head;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}