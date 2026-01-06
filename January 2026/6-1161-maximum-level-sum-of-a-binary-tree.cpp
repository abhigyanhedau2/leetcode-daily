#include <bits/stdc++.h>
using namespace std;

/*

Problem Link - https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/

Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

Example 1:
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.

Example 2:
Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2

*/

/*

Solution 1:

Approach: Level Order Traversal (BFS)

*/

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int maxSum = root->val, res = 1, level = 1;

        while (!q.empty()) {
            int sz = q.size(); 
            int levelSum = 0;

            for (int i = 0; i < sz; i++) {
                TreeNode* top = q.front(); q.pop();
                levelSum += top->val;
                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }

            if (levelSum > maxSum) {
                maxSum = levelSum;
                res = level;
            } 

            level++;
        }

        return res;
    }
};

/*

In this solution, we perform a level order traversal of the binary tree using a queue. For each level, we calculate the sum of the node values. If the sum of the current level exceeds the maximum sum found so far, we update the maximum sum and record the current level. Finally, we return the level with the maximum sum.

Time Complexity: O(n)
Space Complexity: O(n)

*/

int main() {
    return 0;
}