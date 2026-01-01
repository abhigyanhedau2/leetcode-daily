#include <bits/stdc++.h>
using namespace std;

/*

Problem Link - https://leetcode.com/problems/plus-one/description

You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].

*/

/*

Solution 1:

Approach: Array Traversal

*/

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();

        reverse(digits.begin(), digits.end());

        int i = 0;
        bool addOne = true;

        while (i < n && addOne) {
            int sum = digits[i] + 1;
            digits[i] = sum % 10;

            if (sum < 10) addOne = false;

            i++;
        }

        if (addOne) digits.push_back(1);

        reverse(digits.begin(), digits.end());

        return digits;
    }
};

/*

In this solution, we reverse the digits array to make it easier to add one from the least significant digit. We then iterate through the digits, adding one and handling any carry-over. If we finish processing all digits and still have a carry, we append a new digit at the front. Finally, we reverse the array back to its original order.

Time Complexity: O(n)
Space Complexity: O(1)

*/

int main()
{
    return 0;
}