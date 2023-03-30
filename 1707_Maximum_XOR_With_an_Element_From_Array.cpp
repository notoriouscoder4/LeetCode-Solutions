/*
You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi.
In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi.
If all elements in nums are larger than mi, then the answer is -1.

Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

Example 1:
Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
Output: [3,3,7]
Explanation:
1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.

Example 2:
Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
Output: [15,-1,5]

Constraints:
    1 <= nums.length, queries.length <= 10^5
    queries[i].length == 2
    0 <= nums[j], xi, mi <= 10^9
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
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        sort(nums.begin(), nums.end());

        vector<pair<int, pair<int, int>>> offlineQueries;
        int q = queries.size();
        for (int i = 0; i < q; ++i)
        {
            offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
        }

        // qlogq
        sort(offlineQueries.begin(), offlineQueries.end());

        vector<int> ans(q, 0);

        int idx = 0;
        int n = nums.size();
        Trie trie;

        // O(Q * 32 + N * 32)
        for (int i = 0; i < q; ++i)
        {
            int ai = offlineQueries[i].first;
            int xi = offlineQueries[i].second.first;
            int qIdx = offlineQueries[i].second.second;

            while (idx < n && nums[idx] <= ai)
            {
                trie.insert(nums[idx]);
                idx++;
            }

            if (idx == 0)
                ans[qIdx] = -1;
            else
                ans[qIdx] = trie.maxnum(xi);
        }
        return ans;
    }
};