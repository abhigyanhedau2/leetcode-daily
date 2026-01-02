#include <bits/stdc++.h>
using namespace std;

/*

Problem Link - https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description

You are given an integer array nums with the following properties:
- nums.length == 2 * n.
- nums contains n + 1 unique elements.
- Exactly one element of nums is repeated n times.

Return the element that is repeated n times.

Example 1:
Input: nums = [1,2,3,3]
Output: 3

Example 2:
Input: nums = [2,1,2,5,3,2]
Output: 2

Example 3:
Input: nums = [5,1,5,2,5,3,5,4]
Output: 5

*/

/*

Solution 1:

Approach: Array Traversal

*/

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        int len = nums.size();

        for (int k = 1; k <= 3; k++) {
            for (int i = 0; i < len - k; i++) {
                if (nums[i] == nums[i + k]) return nums[i];
            }
        }

        return -1;
    }
};

/*

In this solution, we traverse the array and check for duplicates within a distance of 1 to 3 indices. This works because the repeated element appears n times in an array of size 2n, ensuring that at least two occurrences of the repeated element will be found within this range and other elements are distinct.

Time Complexity: O(n)
Space Complexity: O(1)

*/

int main()
{
    return 0;
}