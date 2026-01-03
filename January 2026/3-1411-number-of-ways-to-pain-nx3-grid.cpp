#include <bits/stdc++.h>
using namespace std;

/*

Problem Link - https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/

You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).

Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 109 + 7.

Example 1:
Input: n = 1
Output: 12
Explanation: There are 12 possible way to paint the grid as shown.

Example 2:
Input: n = 5000
Output: 30228214

*/

/*

Solution 1:

Approach: Dynamic Programming + Math

*/

class Solution
{
public:
    int numOfWays(int n)
    {
        const int MOD = 1e9 + 7;
        long long typeA = 6; // RGY pattern
        long long typeB = 6; // RGR pattern

        for (int i = 2; i <= n; i++) {
            long long newA = (typeA * 2 + typeB * 2) % MOD;
            long long newB = (typeA * 2 + typeB * 3) % MOD;
            typeA = newA;
            typeB = newB;
        }

        return (typeA + typeB) % MOD;
    }
};

/*

In this solution, we categorize the painting patterns into two types:
1. Type A (e.g., RGY, RYG, GRY, GYR, YRG, YGR) - 6 patterns where all three colors are used.
2. Type B (e.g., RGR, RYR, GRG, GYG, YRY, YGY) - 6 patterns where only two colors are used.
We then use dynamic programming to calculate the number of ways to paint the grid row by row, updating the counts of Type A and Type B patterns based on the previous row's counts.

Time Complexity: O(n)
Space Complexity: O(1)

*/

int main()
{
    return 0;
}