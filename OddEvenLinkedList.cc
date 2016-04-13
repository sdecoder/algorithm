
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>

using namespace std;

/**
 * Definition for singly-linked list.
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    if( !head) return head; 

    ListNode* odd = head; 
    ListNode* oddtail = odd; 
    ListNode* even = head -> next; 
    ListNode* evenhead = even; 
    while( odd  && even){
      odd -> next = even -> next; 
      odd = odd -> next; 
      if( !odd ) break; else oddtail = odd; 
      even -> next = odd ->next; 
      even = even -> next; 
    }
    oddtail -> next = evenhead;
    return head;
  }
};

int main(int argc, char const *argv[])
{
  Solution s;
  return 0;
}