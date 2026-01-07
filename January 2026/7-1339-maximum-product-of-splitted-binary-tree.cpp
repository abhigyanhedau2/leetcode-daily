#include <bits/stdc++.h>
using namespace std;

/*

Problem Link - https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/

Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)

Example 2:
Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)

*/

/*

Solution 1:

Approach: Depth-first Search (DFS) + Recursion

*/

class Solution
{
public:
    const int MOD = 1e9 + 7;

    int getTreeSum(TreeNode *root) {
        if (root == NULL) return 0;
        return root->val + getTreeSum(root->left) + getTreeSum(root->right);
    }

    long long maxProductHelper(TreeNode *root, long long totalTreeSum) {
        if (root == NULL) return 0;

        long long leftSum = getTreeSum(root->left);
        long long rightSum = getTreeSum(root->right);

        long long breakLeft = leftSum * (totalTreeSum - leftSum);
        long long breakRight = rightSum * (totalTreeSum - rightSum);

        return max({breakLeft, breakRight, maxProductHelper(root->left, totalTreeSum), maxProductHelper(root->right, totalTreeSum)});
    }

    int maxProduct(TreeNode *root) {
        long long totalTreeSum = getTreeSum(root);
        long long ans = maxProductHelper(root, totalTreeSum);
        return ans % MOD;
    }
};

/*

In this solution, we define two helper functions: getTreeSum to calculate the sum of all nodes in the binary tree, and maxProductHelper to recursively explore all possible splits of the tree and calculate the maximum product of the sums of the resulting subtrees.

Time Complexity: O(n^2)
Space Complexity: O(1)

*/

/*

Solution 2:

Approach: Depth-first Search (DFS) + Recursion (Optimized)

*/

class Solution {
public:
    const int MOD = 1e9 + 7;
    long long totalSum = 0;
    long long res = 0;

    long long dfs(TreeNode* root) {
        if (root == NULL) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);
        long long subTreeSum = root->val + left + right;

        res = max(res, subTreeSum * (totalSum - subTreeSum));

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = dfs(root);   
        dfs(root);              
        return res % MOD;
    }
};

/*

In this solution, we optimize the previous approach by calculating the total sum of the tree in the first DFS traversal. In the second DFS traversal, we compute the subtree sums and update the maximum product simultaneously, avoiding redundant calculations.

Time Complexity: O(n)
Space Complexity: O(1)

*/

int main()
{
    return 0;
}