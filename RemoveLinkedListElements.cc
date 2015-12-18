
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
  ListNode *removeElements(ListNode *head, int val) {
    if (head == NULL)
      return NULL;

    struct ListNode *result = head;
    struct ListNode *p = head;
    while (p && p->val == val) {
      struct ListNode *temp = p;
      p = p->next;
      free(temp);
    }
    result = p;

    while (p) {
      if (p->next && p->next->val == val) {
        struct ListNode *temp = p->next;
        p->next = p->next->next;
        free(temp);
        continue;
      }
      p = p->next;
    }

    return result;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}