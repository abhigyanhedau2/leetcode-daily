#include <bits/stdc++.h>
using namespace std;

/*

Problem Link - https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/

Given two arrays nums1 and nums2.

Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.

A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).

Example 1:
Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
Output: 18
Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
Their dot product is (2*3 + (-2)*(-6)) = 18.

Example 2:
Input: nums1 = [3,-2], nums2 = [2,-6,7]
Output: 21
Explanation: Take subsequence [3] from nums1 and subsequence [7] from nums2.
Their dot product is (3*7) = 21.

Example 3:
Input: nums1 = [-1,-1], nums2 = [1,1]
Output: -1
Explanation: Take subsequence [-1] from nums1 and subsequence [1] from nums2.
Their dot product is -1.

*/

/*

Solution 1:

Approach: Top-Down Dynamic Programming 

*/

class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>& dp) {
        int n = nums1.size(), m = nums2.size();
        if (i == n || j == m) return -1e9;
        if (dp[i][j] != INT_MIN) return dp[i][j];

        int take = nums1[i]*nums2[j] + max(0, solve(nums1, nums2, i+1, j+1, dp));
        int dontTakeNums1 = solve(nums1, nums2, i+1, j, dp);
        int dontTakeNums2 = solve(nums1, nums2, i, j+1, dp);

        return dp[i][j] = max({take, dontTakeNums1, dontTakeNums2});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        return solve(nums1, nums2, 0, 0, dp);
    }
};

/*

In this solution, we define a recursive function `solve` that takes the current indices `i` and `j` for `nums1` and `nums2`, respectively, along with a memoization table `dp`. The function computes the maximum dot product of subsequences starting from these indices. 

In the solve function, we have three choices:
1. Take the current elements from both arrays and add their product to the result of the recursive call for the next indices. We also consider the case where we do not add anything further (hence the `max(0, ...)`).
2. Skip the current element in `nums1` and move to the next element in `nums1`.
3. Skip the current element in `nums2` and move to the next element in `nums2`.

Time Complexity: O(n*m)
Space Complexity: O(n*m)

*/

int main() {
    return 0;
}