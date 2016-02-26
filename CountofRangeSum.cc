
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>


using namespace std;


typedef long long LL;
struct SegmentTreeNode{
    LL L, R;
    int cnt;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(LL L, LL R){
        L = L;
        R = R;
        cnt = 0;
        left = NULL;
        right = NULL;
    }
};

class SegmentTree{
    SegmentTreeNode* root;
    SegmentTreeNode* buildTree(std::vector<LL> &nums, int L, int R){
        if( L > R ) return NULL;
        SegmentTreeNode* root = new SegmentTreeNode(nums[L], nums[R]);
        if(L == R) return root;
        int mid = (L + R ) >> 1;
        root -> left = buildTree(nums, L, mid-1);
        root -> right = buildTree(nums, mid+1, R);
        return root;
    }

    void update(SegmentTreeNode* root, LL val){
        if( root && root-> L <= val && val <= root-> R){
            root-> cnt++;
            update(root->left, val);
            update(root->right, val);
        }
    }

    int sum(SegmentTreeNode* root, LL L, LL R){
        if(!root || root-> R < L || R < root->L ) return 0;
        if(L <= root-> L && root->R <= R) return root-> cnt;
        return sum(root->left, L, R) + sum(root->right, L, R);
    }

public:
    SegmentTree(vector<LL> &nums, int L, int R){
        root = buildTree(nums, L, R);
    }
    int sum(LL l, LL r){
        return sum(root, l, r);
    }

    void update(LL val){
        update(root, val);
    }

};

class Solution{
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.size() ==0 ) return 0;
        vector<LL> sum_array(nums.size(), 0);
        sum_array[0] = nums[0];
        for (int i = 1; i < sum_array.size(); ++i) {
            sum_array[i] = nums[i] + sum_array[i-1];
        }
        LL sum = sum_array[sum_array.size() - 1];
        sort(sum_array.begin(), sum_array.end());
        auto t = unique(sum_array.begin(), sum_array.end());
        SegmentTree tree(sum_array, 0, t - sum_array.begin() -1);
        int ans = 0; 
        for(int i = nums.size() -1; i >= 0; --i){
            tree.update(sum); 
            sum -= nums[i];
            ans += tree.sum(lower+ sum, upper + sum);
        }
        
        return ans;
        
    }
};



int main(int argc, char const *argv[])
{
    Solution s; 
    return 0;
}