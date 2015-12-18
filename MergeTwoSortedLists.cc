#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (l1 == NULL)
      return l2;

    if (l2 == NULL)
      return l1;

    ListNode *p = l1;
    ListNode *q = l2;
    ListNode *head = NULL;
    ListNode *curNode = NULL;

    while (p && q) {
      if (head == NULL) {
        if (p->val < q->val) {
          head = curNode = p;
          p = p->next;
          // curNode->next = NULL;
        } else {
          head = curNode = q;
          q = q->next;
          //    curNode->next = NULL;
        }
      } else {
        if (p->val < q->val) {
          curNode->next = p;
          curNode = p;
          p = p->next;
          //  curNode->next = NULL;
        } else {
          curNode->next = q;
          curNode = q;
          q = q->next;
          // curNode->next = NULL;
        }
      }
    }

    if (p)
      curNode->next = p;
    else if (q)
      curNode->next = q;

    return head;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}