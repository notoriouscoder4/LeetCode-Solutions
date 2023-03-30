/*
You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1.
Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

You are given two arrays redEdges and blueEdges where:

redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.

Example 1:
Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
Output: [0,1,-1]

Example 2:
Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
Output: [0,1,-1]

Constraints:
    1 <= n <= 100
    0 <= redEdges.length, blueEdges.length <= 400
    redEdges[i].length == blueEdges[j].length == 2
    0 <= ai, bi, uj, vj < n
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // red->0 and blue->1
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &it : redEdges)
        {
            adj[it[0]].push_back({it[1], 0});
        }
        for (auto &it : blueEdges)
        {
            adj[it[0]].push_back({it[1], 1});
        }
        vector<int> ans(n, -1);
        vector<vector<bool>> visited(n, vector<bool>(2));

        queue<vector<int>> q;
        q.push({0, 0, -1}); // node, steps, color
        visited[0][0] = true;
        visited[0][1] = true;
        ans[0] = 0;

        while (!q.empty())
        {
            vector<int> curr = q.front();
            q.pop();
            int node = curr[0], steps = curr[1], prevColor = curr[2];

            for (auto &neighbour : adj[node])
            {
                int nbr_node = neighbour.first;
                int nbr_color = neighbour.second;
                if (!visited[nbr_node][nbr_color] && nbr_color != prevColor)
                {
                    visited[nbr_node][nbr_color] = true;
                    q.push({nbr_node, 1 + steps, nbr_color});
                    if (ans[nbr_node] == -1)
                    {
                        ans[nbr_node] = 1 + steps;
                    }
                }
            }
        }
        return ans;
    }
};