/*
There is a tree (i.e. a connected, undirected graph with no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges.

You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node.
You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

A good path is a simple path that satisfies the following conditions:

The starting node and the ending node have the same value.
All nodes between the starting node and the ending node have values less than or equal to the starting node (i.e. the starting node's value should be the maximum value along the path).
Return the number of distinct good paths.

Note that a path and its reverse are counted as the same path. For example, 0 -> 1 is considered to be the same as 1 -> 0. A single node is also considered as a valid path.

Example 1:
Input: vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
Output: 6
Explanation: There are 5 good paths consisting of a single node.
There is 1 additional good path: 1 -> 0 -> 2 -> 4.
(The reverse path 4 -> 2 -> 0 -> 1 is treated as the same as 1 -> 0 -> 2 -> 4.)
Note that 0 -> 2 -> 3 is not a good path because vals[2] > vals[0].

Example 2:
Input: vals = [1,1,2,2,3], edges = [[0,1],[1,2],[2,3],[2,4]]
Output: 7
Explanation: There are 5 good paths consisting of a single node.
There are 2 additional good paths: 0 -> 1 and 2 -> 3.

Example 3:
Input: vals = [1], edges = []
Output: 1
Explanation: The tree consists of only one node, so there is one good path.

Constraints:
    n == vals.length
    1 <= n <= 3 * 10^4
    0 <= vals[i] <= 10^5
    edges.length == n - 1
    edges[i].length == 2
    0 <= ai, bi < n
    ai != bi
    edges represents a valid tree.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(vector<int> &parent, int a) // find parent of a
    {
        if (a == parent[a])
            return a;
        parent[a] = find(parent, parent[a]);
        return parent[a];
    }

    int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges)
    {
        int n = vals.size();
        vector<int> parent(n); // denotes for all the nodes what are the parents of all nodes

        map<int, int> maxElement; // it represents for each of node values what is the maximum value contained in that particular subtree
        map<int, int> count;      // it represents the number of nodes having maximum value

        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            maxElement[i] = vals[i]; // because for every node since that is a single node because we are starting with n number of subtrees that will be maximum value
            count[i] = 1;
        }

        sort(edges.begin(), edges.end(), [&](const vector<int> &a, vector<int> &b)
             { 
                int m = max(vals[a[0]], vals[a[1]]);
                int n = max(vals[b[0]], vals[b[1]]);
                return m < n; });

        int ans = n;

        for (auto &edge : edges)
        {
            int a = find(parent, edge[0]);
            int b = find(parent, edge[1]);

            if (maxElement[a] != maxElement[b])
            {
                if (maxElement[a] > maxElement[b])
                    parent[b] = a;
                else
                    parent[a] = b;
            }
            else
            {
                parent[a] = b;
                ans += count[a] * count[b];
                count[b] += count[a];
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> vals = {1, 3, 2, 1, 3};
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}};

    Solution obj;
    auto ans = obj.numberOfGoodPaths(vals, edges);
    cout << ans << "\n";

    return 0;
}