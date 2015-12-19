#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr) return head;

    ListNode* curr = head->next;
    head->next = nullptr;

    while (curr != nullptr) {
      ListNode* tmpHead = head;
      ListNode* prev = nullptr;
      ListNode* next = curr->next;
      while (tmpHead != nullptr && tmpHead->val <= curr->val) {
        prev = tmpHead;
        tmpHead = tmpHead->next;
      }

      if (prev != nullptr) {
        // insert
        if (prev->next) {
          curr->next = prev->next;
          prev->next = curr;
        } else {
          prev->next = curr;
          curr->next = nullptr;
        }
      } else {
        curr->next = head;
        head = curr;
      }
      curr = next;
    }
    return head;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  return 0;
}