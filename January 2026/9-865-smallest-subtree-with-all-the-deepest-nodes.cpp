#include <bits/stdc++.h>
using namespace std;

/*

Problem Link - https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/

Given the root of a binary tree, the depth of each node is the shortest distance to the root.

Return the smallest subtree such that it contains all the deepest nodes in the original tree.

A node is called the deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest nodes of the tree.
Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.

Example 2:
Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree.

Example 3:
Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest node in the tree is 2, the valid subtrees are the subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.

*/

/*

Solution 1:

Approach: Depth-First Search (DFS) with Post-order Traversal

*/

class Solution
{
public:
    pair<TreeNode *, int> solve(TreeNode *root) {
        if (root == NULL) return {NULL, 0};
        
        pair<TreeNode *, int> left = solve(root->left);
        pair<TreeNode *, int> right = solve(root->right);

        if (left.second == right.second) return {root, left.second + 1};
        else if (left.second > right.second) return {left.first, left.second + 1};
        return {right.first, right.second + 1};
    }

    TreeNode *subtreeWithAllDeepest(TreeNode *root) {
        return solve(root).first;
    }
};

/*

In this solution, we define a helper function solve that performs a depth-first search (DFS) on the binary tree. The function returns a pair consisting of the subtree root that contains all the deepest nodes and the depth of the deepest nodes in the subtree. 

In the solve function, we recursively call the function on the left and right children of the current node. We then compare the depths returned from the left and right subtrees:
- If the depths are equal, it means the deepest nodes are present in both subtrees, so we return the current node as the root of the subtree containing all deepest nodes.
- If the left depth is greater, we return the left subtree's root.
- If the right depth is greater, we return the right subtree's root.

Time Complexity: O(n)
Space Complexity: O(h)

*/

int main()
{
    return 0;
}