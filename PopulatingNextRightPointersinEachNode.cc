#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>

using namespace std;


struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };
 
class Solution {
public:
   void connect(TreeLinkNode *root) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        if (root) {  
            if (root->left) {  
                root->left->next = root->right;  
            }  
            if (root->right) {  
                root->right->next = root->next ? root->next->left : NULL;  
            }  
            connect(root->left);  
            connect(root->right);  
        }  
    }  
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}