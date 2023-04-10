/*

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(colors.size()), cnt(colors.size(), vector<int>(26));
        vector<int> indegrees(colors.size());

        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            ++indegrees[edge[1]];
        }
        vector<int> q;
        for (int i = 0; i < colors.size(); i++)
            if (indegrees[i] == 0)
                q.push_back(i);

        int res = 0, processed = 0;
        while (!q.empty())
        {
            vector<int> q1;
            for (auto i : q)
            {
                ++processed;
                res = max(res, ++cnt[i][colors[i] - 'a']);
                for (auto j : adj[i])
                {
                    for (auto k = 0; k < 26; k++)
                        cnt[j][k] = max(cnt[j][k], cnt[i][k]);
                    if (--indegrees[j] == 0)
                        q1.push_back(j);
                }
            }
            swap(q, q1);
        }
        return processed != colors.size() ? -1 : res;
    }
};

class Solution_easy_code
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.size();
        vector<int> indegrees(n, 0);
        vector<vector<int>> graph(n, vector<int>());
        for (vector<int> &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            indegrees[edge[1]]++;
        }
        queue<int> zero_indegree;
        for (int i = 0; i < n; i++)
        {
            if (indegrees[i] == 0)
            {
                zero_indegree.push(i);
            }
        }
        vector<vector<int>> counts(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++)
        {
            counts[i][colors[i] - 'a']++;
        }
        int max_count = 0;
        int visited = 0;
        while (!zero_indegree.empty())
        {
            int u = zero_indegree.front();
            zero_indegree.pop();
            visited++;
            for (int v : graph[u])
            {
                for (int i = 0; i < 26; i++)
                {
                    counts[v][i] = max(counts[v][i], counts[u][i] + (colors[v] - 'a' == i ? 1 : 0));
                }
                indegrees[v]--;
                if (indegrees[v] == 0)
                {
                    zero_indegree.push(v);
                }
            }
            max_count = max(max_count, *max_element(counts[u].begin(), counts[u].end()));
        }
        return visited == n ? max_count : -1;
    }
};