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
  bool isPalindrome(ListNode *head) {
    ListNode *slow_ptr = head, *fast_ptr = head;
    ListNode *second_half, *prev_of_slow_ptr = head;
    ListNode *midnode = NULL; // To handle odd size list
    bool res = true;          // initialize result

    if (head != NULL && head->next != NULL) {
      while (fast_ptr != NULL && fast_ptr->next != NULL) {
        fast_ptr = fast_ptr->next->next;
        prev_of_slow_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
      }

      if (fast_ptr != NULL) {
        midnode = slow_ptr;
        slow_ptr = slow_ptr->next;
      }

      // Now reverse the second half and compare it with first half
      second_half = slow_ptr;
      prev_of_slow_ptr->next = NULL;         // NULL terminate first half
      reverse(&second_half);                 // Reverse the second half
      res = compareLists(head, second_half); // compare
    }
    return res;
  }

  void reverse(ListNode **head_ref) {
    ListNode *prev = NULL;
    ListNode *current = *head_ref;
    ListNode *next;
    while (current != NULL) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    *head_ref = prev;
  }

  bool compareLists(ListNode *head1, ListNode *head2) {
    ListNode *temp1 = head1;
    ListNode *temp2 = head2;

    while (temp1 && temp2) {
      if (temp1->val == temp2->val) {
        temp1 = temp1->next;
        temp2 = temp2->next;
      } else
        return 0;
    }

    /* Both are empty reurn 1*/
    if (temp1 == NULL && temp2 == NULL)
      return 1;

    /* Will reach here when one is NULL
      and other is not */
    return 0;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}