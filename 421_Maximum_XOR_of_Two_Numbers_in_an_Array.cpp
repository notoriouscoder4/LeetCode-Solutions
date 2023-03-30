/*
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

Example 1:
Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.

Example 2:
Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127

Constraints:
    1 <= nums.length <= 2 * 10^5
    0 <= nums[i] <= 2^31 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[2];
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(int num)
    {
        TrieNode *node = root;
        for (int i = 31; i >= 0; --i)
        {
            int bit = (num >> i) & 1;
            if (!node->children[bit])
                node->children[bit] = new TrieNode();
            node = node->children[bit];
        }
    }

    int maxnum(int num)
    {
        TrieNode *node = root;
        int maxi = 0;
        for (int i = 31; i >= 0; --i)
        {
            int bit = (num >> i) & 1;
            // If bit -> 0 => we need 1 and if bit -> 1 => we need 0 i.e. (1 - bit)
            if (!node->children[1 - bit])
            {
                node = node->children[bit];
            }
            else
            {
                maxi = maxi | (1 << i);
                node = node->children[1 - bit];
            }
        }
        return maxi;
    }
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int maxXOR = 0;
        Trie trie;

        for (int i = 0; i < nums.size(); ++i)
            trie.insert(nums[i]);

        for (int i = 0; i < nums.size(); ++i)
            maxXOR = max(maxXOR, trie.maxnum(nums[i]));

        return maxXOR;
    }
};

int main()
{
    vector<int> nums = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};

    Solution obj;
    auto ans = obj.findMaximumXOR(nums);
    cout << ans << "\n";

    return 0;
}