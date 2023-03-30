/*
You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted at node 0 consisting of n nodes numbered from 0 to n - 1.
The tree is represented by a 0-indexed array parent of size n, where parent[i] is the parent of node i.
Since node 0 is the root, parent[0] == -1.

You are also given a string s of length n, where s[i] is the character assigned to node i.

Return the length of the longest path in the tree such that no pair of adjacent nodes on the path have the same character assigned to them.



Example 1:
Input: parent = [-1,0,0,1,1,2], s = "abacbe"
Output: 3
Explanation: The longest path where each two adjacent nodes have different characters in the tree is the path: 0 -> 1 -> 3. The length of this path is 3, so 3 is returned.
It can be proven that there is no longer path that satisfies the conditions.

Example 2:
Input: parent = [-1,0,0,0], s = "aabc"
Output: 3
Explanation: The longest path where each two adjacent nodes have different characters is the path: 2 -> 0 -> 3. The length of this path is 3, so 3 is returned.

Constraints:
    n == parent.length == s.length
    1 <= n <= 10^5
    0 <= parent[i] <= n - 1 for all i >= 1
    parent[0] == -1
    parent represents a valid tree.
    s consists of only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(int node, int parent, vector<vector<int>> &adjList, string &s, int &ans)
    {
        // to store the max length upto that node including it , so initialize with 1.
        int maxPath = 1;

        // only take children
        for (auto &child : adjList[node])
        {
            // check only for children
            if (child != parent)
            {
                int temp = dfs(child, node, adjList, s, ans);
                // if node character and its child character is not equal
                if (s[node] != s[child])
                {
                    // update the ans with maximum value.
                    // update the maxpath length to return to its parent.
                    ans = max(ans, maxPath + temp);
                    maxPath = max(maxPath, 1 + temp);
                }
            }
        }
        // return the maxpath for current node.
        return maxPath;
    }
    int longestPath(vector<int> &parent, string s)
    {
        int n = s.size();

        int ans = 1;
        vector<vector<int>> adjlist(n);
        // First step is to convert the edges into the graph
        // so as given undirected graph so we have made 2d vector for graph
        for (int i = 1; i < n; ++i)
        {
            adjlist[i].push_back(parent[i]);
            adjlist[parent[i]].push_back(i);
        }
        
        // call dfs.
        dfs(0, -1, adjlist, s, ans);
        return ans;
    }
};

int main()
{
    vector<int> parent = {-1, 0, 0, 1, 1, 2};
    string s = "abacbe";

    Solution obj;
    auto ans = obj.longestPath(parent, s);
    cout << "the length of the longest path in the tree is: " << ans << "\n";

    return 0;
}