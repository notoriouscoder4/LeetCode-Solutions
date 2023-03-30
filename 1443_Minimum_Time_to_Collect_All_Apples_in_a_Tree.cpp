/*
Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices.
You spend 1 second to walk over one edge of the tree.
Return the minimum time in seconds you have to spend to collect all apples in the tree, starting at vertex 0 and coming back to this vertex.

The edges of the undirected tree are given in the array edges,
where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi.
Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple; otherwise, it does not have any apple.



Example 1:
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
Output: 8
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.

Example 2:
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
Output: 6
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.

Example 3:
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
Output: 0

Constraints:
    1 <= n <= 10^5
    edges.length == n - 1
    edges[i].length == 2
    0 <= ai < bi <= n - 1
    from[i] < to[i]
    hasApple.length == n
*/

#include <bits/stdc++.h>
using namespace std;

/*
Complexity Analysis
Here, n be the number of nodes.

Time complexity: O(n)

1.  Each node is visited by the dfs function once, which takes O(n) time in total.
    We also iterate over the edges of every node once (since we don't visit a node more than once, we don't iterate its edges more than once),
    which adds O(n) time since we have n−1 edges.

2.  We also require O(n) time to initialize the adjacency list and the visit array.

Space complexity: O(n)
1.  The recursion call stack used by dfs can have no more than nnn elements in the worst-case scenario.
    It would take up O(n) space in that case.
2.  We also require O(n) space for the adjacency list and the visit array.
*/
class Solution
{
public:
    int dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &hasApple)
    {
        int totalTime = 0, childTIme = 0;
        for (auto child : adj[node])
        {
            if (child == parent)
                continue;
            childTIme = dfs(child, node, adj, hasApple);
            // childTime > 0 indicates subtree of child has apples. Since the root node of the
            // subtree does not contribute to the time, even if it has an apple, we have to check it independently.
            if (childTIme || hasApple[child])
                totalTime = totalTime + childTIme + 2;
        }
        return totalTime;
    }

public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<vector<int>> adj(n);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return dfs(0, -1, adj, hasApple);
    }
};

int main()
{
    int n = 7;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
    vector<bool> hasApple = {false, false, true, false, true, true, false};

    Solution obj;
    auto ans = obj.minTime(n, edges, hasApple);
    cout << ans << "\n";

    return 0;
}