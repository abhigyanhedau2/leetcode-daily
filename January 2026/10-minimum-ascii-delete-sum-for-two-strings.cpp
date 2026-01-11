#include <bits/stdc++.h>
using namespace std;

/*

Problem Link - https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/

Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

Example 2:
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.

*/

/*

Solution 1:

Approach: Dynamic Programming

*/

class Solution
{
public:
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {
        int m = s1.size(), n = s2.size();

        if (i == m) {
            int sum = 0;
            for (int k = j; k < n; k++) sum += s2[k];
            return sum;
        } else if (j == n) {
            int sum = 0;
            for (int k = i; k < m; k++) sum += s1[k];
            return sum;
        } else if (dp[i][j] != -1) return dp[i][j];
        else if (s1[i] == s2[j]) return dp[i][j] = solve(s1, s2, i + 1, j + 1, dp);
        else {
            int delete1 = s1[i] + solve(s1, s2, i + 1, j, dp);
            int delete2 = s2[j] + solve(s1, s2, i, j + 1, dp);
            return dp[i][j] = min(delete1, delete2);
        }
    }

    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(s1, s2, 0, 0, dp);
    }
};

/*

In this solution, we use a recursive function with memoization to compute the minimum ASCII delete sum. The function `solve` takes the current indices of both strings and calculates the cost based on whether the characters at those indices match or not. If they match, we move to the next characters in both strings. If they don't match, we consider two options: deleting a character from either string and adding its ASCII value to the total cost. We store intermediate results in a 2D vector `dp` to avoid redundant calculations.

Time Complexity: O(m*n)
Space Complexity: O(m*n)

*/

int main()
{
    return 0;
}