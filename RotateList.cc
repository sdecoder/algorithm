#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#include <string>
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
  ListNode *rotateRight(ListNode *head, int k) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (head == NULL || head->next == NULL || k == 0) {
      return head;
    }

    int length = 0;
    ListNode *ptr = head, *tail = head;
    while (ptr != NULL) {
      length++;
      tail = ptr;
      ptr = ptr->next;
    }
    k %= length;

    ptr = head;
    for (int i = 0; i < length - k - 1; i++) {
      ptr = ptr->next;
    }

    tail->next = head;
    head = ptr->next;
    ptr->next = NULL;

    return head;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}