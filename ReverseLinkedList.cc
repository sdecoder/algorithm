

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head) {
  if (head == NULL)
    return NULL;
  struct ListNode *pNewHead = NULL;
  struct ListNode *pre = NULL;
  struct ListNode *cur = head;
  while (cur != NULL) {
    if (cur->next == NULL)
      pNewHead = cur; // find reversed head

    struct ListNode *temp = cur->next; // store next node
    cur->next = pre;                   // reverse
    pre = cur;                         // move forward
    cur = temp;
  }
  return pNewHead;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}