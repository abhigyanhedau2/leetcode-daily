#include <bits/stdc++.h>
using namespace std;

/*

Problem Link - https://leetcode.com/problems/four-divisors/description/

Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.

Example 1:
Input: nums = [21,4,7]
Output: 32
Explanation:
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.

Example 2:
Input: nums = [21,21]
Output: 64

Example 3:
Input: nums = [1,2,3,4,5]
Output: 0


*/

/*

Solution 1:

Approach: Array Traversal + Divisor Counting

*/

class Solution
{
public:
    pair<bool, int> solve(int num)
    {
        if (num <= 3) return {false, -1};

        int sum = num + 1;
        int divCount = 2;

        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0) {
                divCount++;
                sum += i;

                if (i != num / i) {
                    divCount++;
                    sum += num / i;
                }

                if (divCount > 4) return {false, -1};
            }
        }

        if (divCount == 4) return {true, sum};
        return {false, -1};
    }

    int sumFourDivisors(vector<int> &nums)
    {
        int sum = 0;
        for (int num : nums) {
            auto res = solve(num);
            if (res.first) sum += res.second;
        }
        return sum;
    }
};

/*

In this solution, we define a helper function `solve` that checks if a number has exactly four divisors and calculates their sum. The main function `sumFourDivisors` iterates through the input array, using the helper function to accumulate the sum of divisors for numbers with exactly four divisors.

Time Complexity: O(n * sqrt(m))
Space Complexity: O(1)

*/

int main()
{
    return 0;
}