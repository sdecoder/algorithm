/*Recover Binary Search Tree My Submissions Question
Total Accepted: 44764 Total Submissions: 176934 Difficulty: Hard
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a
constant space solution?
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on
OJ.

Subscribe to see which companies asked this question*/


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
#include <stack>
#include <list>

using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {  
public:  
    void recoverTree(TreeNode *root) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        TreeNode *n1=NULL;  
        TreeNode *n2=NULL;  
        TreeNode *prev=NULL;  
        findTwoNodes(root,n1,n2,prev);  
          
        if(n1!=NULL && n2!=NULL)  
        {  
            int tmp=n2->val;  
            n2->val=n1->val;  
            n1->val=tmp;  
        }  
    }  
    void findTwoNodes(TreeNode *root, TreeNode *&n1, TreeNode *&n2, TreeNode *&prev)  
    {  
        if(root==NULL) return;  
          
        findTwoNodes(root->left,n1,n2,prev);  
        if(prev!=NULL && prev->val > root->val)  
        {  
            n2=root;  
            if(n1==NULL)  
            {  
                n1=prev;  
            }  
        }  
        prev=root;  
        findTwoNodes(root->right,n1,n2,prev);  
    }  
};  


int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}