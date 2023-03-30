#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dfs(string &labels, int node, int parent, vector<vector<int>> &adjList, vector<int> &ans)
    {
        // Store count of all alphabets in the subtree of the node.
        vector<int> nodeCounts(26);

        for (auto &child : adjList[node])
        {
            if (child == parent)
                continue;
            // it will return count vector for childern.
            vector<int> temp = dfs(labels, child, node, adjList, ans);
            // add temp freq to count freq .
            for (int i = 0; i < 26; ++i)
                nodeCounts[i] += temp[i];
        }
        //  cal for current node also and add it to the count vector
        int ch = labels[node] - 'a'; // for b i.e index ch = 1;
        nodeCounts[ch]++;

        // store for the currentNode in ans.
        ans[node] = nodeCounts[ch];
        return nodeCounts;
    }

    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        vector<vector<int>> adjList;
        for (auto &edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<int> ans(n, 0);
        // current node =0 , parent node =-1,distance or level from root.
        dfs(labels, 0, -1, adjList, ans);
        return ans;
    }
};

int main()
{
    int n = 7;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
    string labels = "abaedcd";

    Solution obj;
    auto ans = obj.countSubTrees(n, edges, labels);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << "\n";

    return 0;
}