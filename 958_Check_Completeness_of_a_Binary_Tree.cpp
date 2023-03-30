/*
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.

Example 2:
Input: root = [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.

Constraints:
    The number of nodes in the tree is in the range [1, 100].
    1 <= Node.val <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

/** Definition for a binary tree node. */
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
    bool isCompleteTree(TreeNode *root)
    {
        // Base Case: An empty tree is complete Binary Tree
        if (root == NULL)
            return true;

        // Create an empty queue
        queue<TreeNode *> q;
        q.push(root);

        // Create a flag variable which will be set true when a non full node is seen
        bool flag = false;

        // Do level order traversal using queue.
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            // check if left child is present
            if (node->left)
            {
                // If we have seen a non full node, and we see a node with non-empty left child
                // then the given tree is not a complete binary tree
                if (flag == true)
                    return false;
                q.push(node->left);
            }
            // If this a non-full node, set the flag as true
            else
                flag = true;

            // check if right child is present
            if (node->right)
            {
                // If we have seen a non full node, and we see a node with non-empty right child
                // then the given tree is not a complete binary tree
                if (flag == true)
                    return false;
                q.push(node->right);
            }
            // If this a non-full node, set the flag as true
            else
                flag = true;
        }
        // If we reach here, then the tree is complete binary tree
        return true;
    }
};