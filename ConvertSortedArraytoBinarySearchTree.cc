#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *createTree(vector<int> &num, int left, int right)
    {
        if (left > right)
            return NULL;
            
        int mid = (left + right) / 2;
        
        TreeNode *leftNode = createTree(num, left, mid - 1);
        TreeNode *rightNode = createTree(num, mid + 1, right);
        
        TreeNode *node = new TreeNode(num[mid]);
        
        node->left = leftNode;
        node->right = rightNode;
        
        return node;
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return createTree(num, 0, num.size() - 1);    
    }
};

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}