/*
You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.

You are also given two integers node1 and node2.

Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.

Note that edges may contain cycles.



Example 1:


Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
Output: 2
Explanation: The distance from node 0 to node 2 is 1, and the distance from node 1 to node 2 is 1.
The maximum of those two distances is 1. It can be proven that we cannot get a node with a smaller maximum distance than 1, so we return node 2.
Example 2:


Input: edges = [1,2,-1], node1 = 0, node2 = 2
Output: 2
Explanation: The distance from node 0 to node 2 is 2, and the distance from node 2 to itself is 0.
The maximum of those two distances is 2. It can be proven that we cannot get a node with a smaller maximum distance than 2, so we return node 2.


Constraints:

n == edges.length
2 <= n <= 10^5
-1 <= edges[i] < n
edges[i] != i
0 <= node1, node2 < n
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int n = edges.size();
        vector<int> adj[n];
        for (int i = 0; i < n; ++i)
        {
            if (edges[i] != -1)
                adj[i].push_back(edges[i]);
        }

        unordered_map<int, int> dist1, dist2;
        queue<int> q1, q2;
        vector<bool> vis1(n, false), vis2(n, false);

        // BFS1
        q1.push(node1);
        vis1[node1] = true;
        dist1[node1] = 0;

        while (!q1.empty())
        {
            int curr = q1.front();
            q1.pop();

            for (auto neighbor : adj[curr])
            {
                if (!vis1[neighbor])
                {
                    dist1[neighbor] = dist1[curr] + 1;
                    vis1[neighbor] = true;
                    q1.push(neighbor);
                }
            }
        }

        // BFS2
        q2.push(node2);
        vis2[node2] = true;
        dist2[node2] = 0;

        while (!q2.empty())
        {
            int curr = q2.front();
            q2.pop();

            for (auto neighbor : adj[curr])
            {
                if (!vis2[neighbor])
                {
                    dist2[neighbor] = dist2[curr] + 1;
                    vis2[neighbor] = true;
                    q2.push(neighbor);
                }
            }
        }

        int maxDis = INT_MAX, ans = -1;
        for (auto it : dist1)
        {
            int ele = it.first;
            if (dist2.find(ele) != dist2.end())
            {
                int currDis = max(dist1[ele], dist2[ele]);
                if (currDis < maxDis)
                {
                    maxDis = currDis;
                    ans = ele;
                }
                else if (currDis == maxDis && ans > ele)
                {
                    ans = ele;
                }
            }
        }
        return ans;
    }
};