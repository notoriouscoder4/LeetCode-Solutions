/*
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes),
where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

Example 2:
Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

Example 3:
Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).

Constraints:
    The number of nodes in the tree is in the range [1, 3000].
    -100 <= Node.val <= 100
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

/*
Intuition
    To find the maximum width of a binary tree,
    we can traverse the tree level by level using a BFS (Breadth-First Search) approach.
    At each level, we keep track of the leftmost and rightmost non-null nodes using two variables.
    We calculate the width of the level by subtracting the index of the leftmost node from the index of the rightmost node and adding 1. Finally, we update the maximum width with the width of the current level if it is greater than the previous maximum.

Approach
    1. Create a queue to store the nodes of the binary tree and another queue to store the indices of the nodes.
    3. Enqueue the root node and its index into the two queues.
    3. Initialize the maximum width to 1.
    4. While the queue is not empty, perform the following steps:
        a. Get the size of the current level.
        b. Traverse the current level and update the left and right indices.
        c. Enqueue the left and right child nodes of the current node into the queues with updated indices.
        d. Update the maximum width with the width of the current level.
    5. Return the maximum width.

Complexity
    Time complexity:
    O(N), where N is the number of nodes in the binary tree. We need to visit every node once.

    Space complexity:
    O(N), where N is the number of nodes in the binary tree. In the worst case, the queue can contain all the nodes of the last level of the binary tree.
*/
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int max_width = 1;              // with 1 Node
        queue<pair<TreeNode *, int>> q; // <TreeNode, It's number>
        q.push({root, 0});              // 0 for root

        while (!q.empty())
        {
            int level_size = q.size();
            int start_index = q.front().second;
            int end_index = q.back().second;
            max_width = max(max_width, (end_index - start_index + 1));

            for (int i = 0; i < level_size; i++)
            {
                auto node_index_pair = q.front();
                TreeNode *node = node_index_pair.first;
                int node_index = node_index_pair.second - start_index;
                q.pop();

                if (node->left != NULL)
                    q.push({node->left, 2LL * node_index + 1});
                if (node->right != NULL)
                    q.push({node->right, 2LL * node_index + 2});
            }
        }
        return max_width;
    }
};