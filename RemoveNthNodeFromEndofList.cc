
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (head == NULL)
      return NULL;

    ListNode *pPre = NULL;
    ListNode *p = head;
    ListNode *q = head;
    for (int i = 0; i < n - 1; i++)
      q = q->next;

    while (q->next) {
      pPre = p;
      p = p->next;
      q = q->next;
    }

    if (pPre == NULL) {
      head = p->next;
      delete p;
    } else {
      pPre->next = p->next;
      delete p;
    }

    return head;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}