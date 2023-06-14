/*
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

Example 1:
Input: root = [4,2,6,1,3]
Output: 1

Example 2:
Input: root = [1,0,48,null,null,12,49]
Output: 1

Constraints:
    The number of nodes in the tree is in the range [2, 10^4].
    0 <= Node.val <= 10^5

Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
    TreeNode *prev = NULL;
    void solve(TreeNode *root, int &ans)
    {
        if (root->left)
            solve(root->left, ans);
        if (prev != NULL)
            ans = min(ans, abs(prev->val - root->val));
        prev = root;
        if (root->right)
            solve(root->right, ans);
    }
    int getMinimumDifference(TreeNode *root)
    {
        int ans = INT_MAX;
        solve(root, ans);
        return ans;
    }
};