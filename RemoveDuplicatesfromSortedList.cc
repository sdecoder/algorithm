
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <climits>


using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (head == NULL)
      return NULL;

    ListNode *pPre = NULL;
    ListNode *p = head;
    int key = INT_MAX;

    while (p) {
      if (key != p->val) {
        key = p->val;
        pPre = p;
        p = p->next;
      } else {
        ListNode *pNext = p->next;
        if (pPre)
          pPre->next = pNext;
        delete p;
        p = pNext;
      }
    }

    return head;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}