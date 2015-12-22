#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#include <sstream>
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/*
[LeetCode] Paint Fence

Problem Description:

There is a fence with n posts, each post can be painted with one of the k
colors.

You have to paint all the posts such that no more than two adjacent fence posts
have the same color.

Return the total number of ways you can paint the fence.

Note:
n and k are non-negative integers.

A dynamic programming problem. This post shares a nice solution and explanation.
Well, this article is simply an organization of this post and its first answer
(also posted by me :-)).

I use s (same) to stand for the number of ways when the last two fences are
painted with the same color (the last element of dp1 in the above post) and d
(different) with d1 and d2 to stand for the last two elements of dp2 in the
above post.

In each loop, dp1[i] = dp2[i - 1] turns into s = d2 and dp2[i] = (k - 1) *
(dp2[i - 2] + dp2[i - 1]) becomes d2 = (k - 1) * (d1 + d2). Moreover, d1 needs
to be set to the oldd2, which is recorded in s. So we have d1 = s.

Finally, the return value dp1[n - 1] + dp2[n - 1] is just s + d2.

The code is as follows.*/
class Solution {
 public:
  int numWays(int n, int k) {
    if (n < 2 || !k) return n * k;
    int s = k, d1 = k, d2 = k * (k - 1);
    for (int i = 2; i < n; i++) {
      s = d2;
      d2 = (k - 1) * (d1 + d2);
      d1 = s;
    }
    return s + d2;
  }
};

int main(int argc, char const *argv[]) { return 0; }