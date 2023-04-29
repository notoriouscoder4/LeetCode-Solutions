/*
An undirected graph of n nodes is defined by edgeList, where edgeList[i] = [ui, vi, disi] denotes an edge between nodes ui and vi with distance disi.
Note that there may be multiple edges between two nodes.

Given an array queries, where queries[j] = [pj, qj, limitj], your task is to determine for each queries[j] whether there is a path between pj and qj such that each edge on the path has a distance strictly less than limitj .

Return a boolean array answer, where answer.length == queries.length and the jth value of answer is true if there is a path for queries[j] is true, and false otherwise.

Example 1:
Input: n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
Output: [false,true]
Explanation: The above figure shows the given graph. Note that there are two overlapping edges between 0 and 1 with distances 2 and 16.
For the first query, between 0 and 1 there is no path where each distance is less than 2, thus we return false for this query.
For the second query, there is a path (0 -> 1 -> 2) of two edges with distances less than 5, thus we return true for this query.

Example 2:
Input: n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
Output: [true,false]
Exaplanation: The above figure shows the given graph.

Constraints:
    2 <= n <= 10^5
    1 <= edgeList.length, queries.length <= 10^5
    edgeList[i].length == 3
    queries[j].length == 3
    0 <= ui, vi, pj, qj <= n - 1
    ui != vi
    pj != qj
    1 <= disi, limitj <= 109
    There may be multiple edges between two nodes.
*/

#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> parent, rank;
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int Find(int x)
    {
        if (parent[x] != x)
            parent[x] = Find(parent[x]);
        return parent[x];
    }

    bool Union(int x, int y)
    {
        int xset = Find(x);
        int yset = Find(y);
        if (xset != yset)
        {
            rank[xset] < rank[yset] ? parent[xset] = yset : parent[yset] = xset;
            rank[xset] += rank[xset] == rank[yset];
            return true;
        }
        return false;
    }
};

class Solution
{
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
    {
        DSU dsu(n);
        for (int i = 0; i < queries.size(); i++)
            queries[i].push_back(i);
        sort(queries.begin(), queries.end(), [&](auto const &a, auto const &b)
             { return a[2] < b[2]; });
        sort(edgeList.begin(), edgeList.end(), [&](auto const &a, auto const &b)
             { return a[2] < b[2]; });

        int i = 0;
        vector<bool> res(queries.size(), false);
        for (auto q : queries)
        {
            while (i < edgeList.size() && edgeList[i][2] < q[2])
            {
                dsu.Union(edgeList[i][0], edgeList[i][1]);
                i++;
            }
            if (dsu.Find(q[0]) == dsu.Find(q[1]))
                res[q[3]] = true;
        }
        return res;
    }
};
