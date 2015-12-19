/*
Given a sorted linked list,
delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *pre, *now, *Head;
    if (!head || !head->next) return head;
    Head = new ListNode(-1);
    Head->next = head;
    pre = Head;
    now = head;
    while (now && now->next) {
      if (now->val == now->next->val) {
        while (now->next && now->val == now->next->val) {
          now = now->next;
        }
        pre->next = now->next;
        now = now->next;
      } else {
        pre = now;
        now = now->next;
      }
    }
    head = Head->next;
    delete (Head);
    return head;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}