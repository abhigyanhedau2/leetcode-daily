#include <bits/stdc++.h>
using namespace std;

/*

Problem Link - https://leetcode.com/problems/maximal-rectangle/description/

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:
Input: matrix = [["0"]]
Output: 0

Example 3:
Input: matrix = [["1"]]
Output: 1

*/

/*

Solution 1:

Approach: Monotonic Stack

*/

class Solution {
public:
    int maxRectangle(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int res = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int val = heights[st.top()]; st.pop();
                int width = st.empty() ? i : i-st.top()-1;
                res = max(res, val*width);
            }

            st.push(i);
        }

        while (!st.empty()) {
            int val = heights[st.top()]; st.pop();
            int width = st.empty() ? n : n-st.top()-1;
            res = max(res, val*width);
        }

        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }

            res = max(res, maxRectangle(heights));
        }
        
        return res;
    }
};

/*

In this solution, we use a monotonic stack to efficiently calculate the largest rectangle area in a histogram for each row of the binary matrix. We maintain a heights array that represents the height of consecutive 1's for each column up to the current row. For each row, we update the heights array and then compute the maximum rectangle area using the maxRectangle function.

Time Complexity: O(m*n)
Space Complexity: O(n)

*/

int main() {
    return 0;
}