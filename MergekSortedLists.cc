#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <stack>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *merge2Lists(ListNode *l1, ListNode *l2) {
    ListNode *head = NULL;
    ListNode *tail = NULL;

    while ((NULL != l1) || (NULL != l2)) {
      int val1 = (NULL == l1 ? INT_MAX : l1->val);
      int val2 = (NULL == l2 ? INT_MAX : l2->val);
      if (val1 < val2) {
        if (NULL == head) {
          head = l1;
          tail = l1;
        } else {
          tail->next = l1;
          tail = l1;
        }
        l1 = l1->next;
      } else {
        if (NULL == head) {
          head = l2;
          tail = l2;
        } else {
          tail->next = l2;
          tail = l2;
        }
        l2 = l2->next;
      }
    }

    return head;
  }

  // recursive algorithm, O(NlogK)
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *head = NULL;
    if (lists.size() == 0) {
      return NULL;
    }

    if (lists.size() == 1) {
      return lists[0];
    }

    ListNode *l1 = lists[0];
    ListNode *l2 = lists[1];

    // merge l1 & l2
    head = merge2Lists(l1, l2);

    // erase uses a supper ending pointer, be careful, here is begin() + 2, not
    // begin() + 1
    lists.erase(lists.begin(), lists.begin() + 2);
    lists.push_back(head);

    return mergeKLists(lists);
  }
};
int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}