/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree
and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]

Constraints:
    1 <= inorder.length <= 3000
    postorder.length == inorder.length
    -3000 <= inorder[i], postorder[i] <= 3000
    inorder and postorder consist of unique values.
    Each value of postorder also appears in inorder.
    inorder is guaranteed to be the inorder traversal of the tree.
    postorder is guaranteed to be the postorder traversal of the tree.
*/

#include <bits/stdc++.h>
using namespace std;

/* Definition for a binary tree node.*/

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
    unordered_map<int, int> inorderMap;

    TreeNode *buildTree_recursive(int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd)
    {
        if (inStart > inEnd || postStart > postEnd)
            return NULL;

        TreeNode *root = new TreeNode(postorder[postEnd]);
        int ind = inorderMap[postorder[postEnd]]; // finding index of root in inorder array
        int x = ind - inStart;                    // no. of elements in LST of inorder array
        root->left = buildTree_recursive(inStart, ind - 1, postorder, postStart, postStart + x - 1);
        root->right = buildTree_recursive(ind + 1, inEnd, postorder, postStart + x, postEnd - 1);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;

        return buildTree_recursive(0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};

int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution obj;
    auto ans = obj.buildTree(inorder, postorder);
    cout << "The root of binary tree is : " << ans->val << "\n";

    return 0;
}