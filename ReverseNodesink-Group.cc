#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

#define LN ListNode *

class Solution {
 public:
  LN reverseKGroup(LN head, int k) {
    if (!head || !head->next || k <= 1) return head;

    LN pFirst = head;
    LN pBefore = NULL;
    LN pKth = pFirst;
    while (1) {
      int cnt = k - 1;
      while (cnt && pKth) {
        pKth = pKth->next;
        cnt--;
      }
      if (cnt > 0 || pKth == NULL) break;
      reverse(pBefore, pFirst, pKth);
      if (pBefore == NULL) head = pFirst;
      pBefore = pKth;
      pFirst = pKth->next;
      pKth = pFirst;
    }
    return head;
  }
  void reverse(LN pBefore, LN& pFirst, LN& pKth) {
    LN pN = pFirst;
    while (pN != pKth) {
      LN pTmp = pN->next;
      pN->next = pKth->next;
      pKth->next = pN;
      pN = pTmp;
    }
    LN pTmp = pFirst;
    pFirst = pKth;
    pKth = pTmp;
    if (pBefore) pBefore->next = pFirst;
  }
};

int main(int argc, char const* argv[]) { return 0; }