#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#include <sstream>
#include <iostream>
#include <vector>
#include <cassert>


using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
  // Start typing your C/C++ solution below
  // DO NOT write int main() function
  assert(head);
  ListNode *pre, *cur;
  pre = head;
  cur = head;
  int step = 0;
  while (step < n && cur != NULL) {
    cur = cur->next;
    step++;
  }
  if (step == n && cur == NULL) {
    head = head->next;
    delete pre;
    return head;
  }
  while (cur->next != NULL) {
    pre = pre->next;
    cur = cur->next;
  }
  ListNode *temp = pre->next;
  pre->next = temp->next;
  delete temp;
  return head;
}

int main(int argc, char const *argv[]) { return 0; }