/*
You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

    1. Choose any node in the binary tree and a direction (right or left).
    2. If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
    3. Change the direction from right to left or from left to right.
    4. Repeat the second and third steps until you can't move in the tree.

Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.

Example 1:
Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).

Example 2:
Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).

Example 3:
Input: root = [1]
Output: 0

Constraints:
    The number of nodes in the tree is in the range [1, 5 * 104].
    1 <= Node.val <= 100
*/

#include <bits/stdc++.h>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int pathLength = 0;
    void dfs(TreeNode *root, int left, int right)
    {
        if (root == NULL)
            return;
        pathLength = max(pathLength, max(left, right));

        if (root->left != NULL)
            dfs(root->left, right + 1, 0);
        if (root->right != NULL)
            dfs(root->right, 0, left + 1);
    }

    int longestZigZag(TreeNode *root)
    {
        dfs(root, 0, 0);
        return pathLength;
    }
};