#include <bits/stdc++.h>
using namespace std;

/*

Problem Link - https://leetcode.com/problems/minimum-time-visiting-all-points/description/

On a 2D plane, there are n points with integer coordinates points[i] = [xi, yi]. Return the minimum time in seconds to visit all the points in the order given by points.

You can move according to these rules:
- In 1 second, you can either:
    - move vertically by one unit,
    - move horizontally by one unit, or
    - move diagonally sqrt(2) units (in other words, move one unit vertically then one unit horizontally in 1 second).
- You have to visit the points in the same order as they appear in the array.
- You are allowed to pass through points that appear later in the order, but these do not count as visits.
 
Example 1:
Input: points = [[1,1],[3,4],[-1,0]]
Output: 7
Explanation: One optimal path is [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]   
Time from [1,1] to [3,4] = 3 seconds 
Time from [3,4] to [-1,0] = 4 seconds
Total time = 7 seconds

Example 2:
Input: points = [[3,2],[-2,2]]
Output: 5

*/

/*

Solution 1:

Approach: Math Calculation

*/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        for (int i = 1; i < points.size(); i++) {
            int dx = abs(points[i][0] - points[i - 1][0]);
            int dy = abs(points[i][1] - points[i - 1][1]);
            time += max(dx, dy);
        }
        return time;
    }
};

/*

In this solution, we iterate through each pair of consecutive points and calculate the differences in the x and y coordinates (dx and dy). The minimum time to move from one point to another is determined by the maximum of these two differences, as diagonal moves can cover both x and y distances simultaneously. We accumulate this time for all pairs of points to get the total minimum time required to visit all points.

Time Complexity: O(n) 
Space Complexity: O(1)

*/

int main() {
    return 0;
}