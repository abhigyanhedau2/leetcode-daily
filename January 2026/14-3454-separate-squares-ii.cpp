#include <bits/stdc++.h>
using namespace std;

/*

Problem Link - https://leetcode.com/problems/separate-squares-ii/description/

You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.

Find the minimum y-coordinate value of a horizontal line such that the total area covered by squares above the line equals the total area covered by squares below the line.

Answers within 10-5 of the actual answer will be accepted.

Note: Squares may overlap. Overlapping areas should be counted only once in this version.

Example 1:
Input: squares = [[0,0,1],[2,2,1]]
Output: 1.00000
Explanation:
Any horizontal line between y = 1 and y = 2 results in an equal split, with 1 square unit above and 1 square unit below. The minimum y-value is 1.

Example 2:
Input: squares = [[0,0,2],[1,1,1]]
Output: 1.00000
Explanation:
Since the blue square overlaps with the red square, it will not be counted again. Thus, the line y = 1 splits the squares into two equal parts.

*/

/*

Solution 1:

Approach: Segment Tree + Line Sweep + Binary Search

*/

class SegmentTree {
private:
    vector<int> count;
    vector<int> covered;
    vector<int> xs;
    int n;

    void modify(int qleft, int qright, int qval, int left, int right, int pos) {
        if (xs[right + 1] <= qleft || xs[left] >= qright) {
            return;
        }
        if (qleft <= xs[left] && xs[right + 1] <= qright) {
            count[pos] += qval;
        } else {
            int mid = (left + right) / 2;
            modify(qleft, qright, qval, left, mid, pos * 2 + 1);
            modify(qleft, qright, qval, mid + 1, right, pos * 2 + 2);
        }

        if (count[pos] > 0) {
            covered[pos] = xs[right + 1] - xs[left];
        } else {
            if (left == right) {
                covered[pos] = 0;
            } else {
                covered[pos] = covered[pos * 2 + 1] + covered[pos * 2 + 2];
            }
        }
    }

public:
    SegmentTree(vector<int>& xs_) : xs(xs_) {
        n = xs.size() - 1;
        count.resize(4 * n, 0);
        covered.resize(4 * n, 0);
    }

    void update(int qleft, int qright, int qval) {
        modify(qleft, qright, qval, 0, n - 1, 0);
    }

    int query() { return covered[0]; }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<int, int, int, int>> events;
        set<int> xsSet;

        for (auto& sq : squares) {
            int x = sq[0], y = sq[1], l = sq[2];
            int xr = x + l;
            events.emplace_back(y, 1, x, xr);
            events.emplace_back(y + l, -1, x, xr);
            xsSet.insert(x);
            xsSet.insert(xr);
        }

        // sort events by y-coordinate
        sort(events.begin(), events.end());
        // discrete coordinates
        vector<int> xs(xsSet.begin(), xsSet.end());
        // initialize the segment tree
        SegmentTree segTree(xs);

        vector<double> psum;
        vector<int> widths;
        double total_area = 0.0;
        int prev = get<0>(events[0]);

        // scan: calculate total area and record intermediate states
        for (auto& [y, delta, xl, xr] : events) {
            int len = segTree.query();
            total_area += 1LL * len * (y - prev);
            segTree.update(xl, xr, delta);
            // record prefix sums and widths
            psum.push_back(total_area);
            widths.push_back(segTree.query());
            prev = y;
        }

        // calculate the target area (half rounded up)
        long long target = (long long)(total_area + 1) / 2;
        // find the first position greater than or equal to target using binary
        // search
        int i =
            lower_bound(psum.begin(), psum.end(), target) - psum.begin() - 1;
        // get the corresponding area, width, and height
        double area = psum[i];
        int width = widths[i], height = get<0>(events[i]);

        return height + (total_area - area * 2) / (width * 2.0);
    }
};

/*

In this solution, we use a segment tree to efficiently manage the coverage of squares along the x-axis as we sweep through the y-coordinates. We record the total area covered at each event and use binary search to find the appropriate y-coordinate that divides the area equally.

In the separateSquares function, we first create events for the bottom and top edges of each square and store unique x-coordinates for discretization. We then sort the events by their y-coordinates and initialize a segment tree to manage the coverage.

In the modify function of the SegmentTree class, we update the coverage based on the events. The query function returns the total covered length at the current state.

Finally, we calculate the total area covered by the squares and use binary search to find the y-coordinate that divides the area equally.

Time Complexity: O(n log n), where n is the number of squares.
Space Complexity: O(n)

*/

int main() {
    return 0;
}