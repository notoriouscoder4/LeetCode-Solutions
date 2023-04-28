/*
Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y.
Also two strings X and Y are similar if they are equal.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar,
but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.
Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list strs of strings where every string in strs is an anagram of every other string in strs.
How many groups are there?

Example 1:
Input: strs = ["tars","rats","arts","star"]
Output: 2

Example 2:
Input: strs = ["omv","ovm"]
Output: 1

Constraints:
    1 <= strs.length <= 300
    1 <= strs[i].length <= 300
    strs[i] consists of lowercase letters only.
    All words in strs have the same length and are anagrams of each other.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution_dfs
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis)
    {
        vis[node] = true;
        for (int neighbor : adj[node])
        {
            if (!vis[neighbor])
                dfs(neighbor, adj, vis);
        }
    }

    bool isSimilar(string &a, string &b)
    {
        int diff = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
                diff++;
        }
        return diff == 0 || diff == 2;
    }

    int numSimilarGroups(vector<string> &strs)
    {
        int n = strs.size();
        vector<vector<int>> adj(n);
        // Form the required graph from the given strings array.
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isSimilar(strs[i], strs[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n);
        int cnt = 0;
        // count the number of connected components
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis);
                cnt++;
            }
        }
        return cnt;
    }
};

class Solution_bfs
{
public:
    void bfs(int node, vector<vector<int>> &adj, vector<bool> &vis)
    {
        queue<int> q;
        q.push(node);
        vis[node] = true;

        while (!q.empty())
        {
            node = q.front();
            q.pop();

            for (int neighbor : adj[node])
            {
                if (!vis[neighbor])
                {
                    vis[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    bool isSimilar(string &a, string &b)
    {
        int diff = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
                diff++;
        }
        return diff == 0 || diff == 2;
    }

    int numSimilarGroups(vector<string> &strs)
    {
        int n = strs.size();
        vector<vector<int>> adj(n);
        // Form the required graph from the given strings array.
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isSimilar(strs[i], strs[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n);
        int cnt = 0;
        // count the number of connected components
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                bfs(i, adj, vis);
                cnt++;
            }
        }
        return cnt;
    }
};

class UnionFind
{
private:
    vector<int> parent, rank;
    int cnt;

public:
    UnionFind(int size)
    {
        parent.resize(size);
        rank.resize(size, 0);
        cnt = size;
        for (int i = 0; i < size; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void union_set(int x, int y)
    {
        int xset = find(x), yset = find(y);
        if (rank[xset] < rank[yset])
            parent[xset] = yset;
        else if (rank[xset] > rank[yset])
            parent[yset] = xset;
        else
        {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
};

class Solution
{
public:
    bool isSimilar(string &a, string &b)
    {
        int diff = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
                diff++;
        }
        return diff == 0 || diff == 2;
    }

    int numSimilarGroups(vector<string> &strs)
    {
        int n = strs.size();
        UnionFind dsu(n);
        int cnt = n;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isSimilar(strs[i], strs[j]) && dsu.find(i) != dsu.find(j))
                {
                    cnt--;
                    dsu.union_set(i, j);
                }
            }
        }
        return cnt;
    }
};