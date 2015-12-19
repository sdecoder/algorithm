#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        vector<pair<int,int>> nums(len, make_pair(0, 0));
        for (int i = 0; i < len; i++) {
            nums[i].second = words[i].length();
            for (auto c : words[i]) {
                nums[i].first |= 1 << (c - 'a');
            }
        }
        sort(nums.begin(), nums.end(), myCompare);
        int maxProd = 0;
        for (int i = len - 1; i >= 0; i--) {
            int val = nums[i].first;
            int l = nums[i].second;
            int target = 1;
            while (target <= val) {
                target <<= 1;
            }
            target >>= 1;
            while (target) {
                while (target & val) {
                    target >>= 1;
                }
                int indexRight = bsMostRight(nums, 0, i - 1, (target << 1) - 1);

                while (target && (!(target & val))) {
                    target >>= 1;
                }
                int indexLeft = bsMostLeft(nums, 0, i - 1, (target << 1));
                for (int j = indexLeft; j <= indexRight; j++) {
                    if (!(nums[j].first & val)) {
                        maxProd = max(maxProd, nums[j].second * l);
                    }
                }
            }
        }
        return maxProd;
    }
    static bool myCompare(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }
    int bsMostLeft(vector<pair<int,int> >& nums, int left, int right, int val) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid].first < val) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    int bsMostRight(vector<pair<int,int> >& nums, int left, int right, int val) {
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid].first > val) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return left;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}