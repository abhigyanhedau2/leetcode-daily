#include <bits/stdc++.h>
using namespace std;

/*

Problem Link - https://leetcode.com/problems/maximum-matrix-sum/description

You are given an n x n integer matrix. You can do the following operation any number of times:

Choose any two adjacent elements of matrix and multiply each of them by -1.
Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.

Example 1:
Input: matrix = [[1,-1],[-1,1]]
Output: 4
Explanation: We can follow the following steps to reach sum equals 4:
- Multiply the 2 elements in the first row by -1.
- Multiply the 2 elements in the first column by -1.

Example 2:
Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
Output: 16
Explanation: We can follow the following step to reach sum equals 16:
- Multiply the 2 last elements in the second row by -1.

*/

/*

Solution 1:

Approach: Count Negatives + Track Minimum Absolute Value

*/

class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        long long totalSum = 0;
        int minAbsVal = INT_MAX;
        int negativeCount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                totalSum += abs(matrix[i][j]);
                if (matrix[i][j] < 0) negativeCount++;
                minAbsVal = min(minAbsVal, abs(matrix[i][j]));
            }
        }

        // Adjust if the count of negative numbers is odd
        if (negativeCount % 2 != 0) totalSum -= 2 * minAbsVal;

        return totalSum;
    }
};

/*

In this solution, we traverse the entire matrix to calculate the total sum of absolute values of the elements, count the number of negative elements, and track the minimum absolute value in the matrix. If the count of negative numbers is odd, we subtract twice the minimum absolute value from the total sum to maximize it.

Time Complexity: O(n^2)
Space Complexity: O(1)

*/

int main()
{
    return 0;
}