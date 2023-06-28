/*
You are given an undirected weighted graph of n nodes (0-indexed),
represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

Example 1:
Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.

Example 2:
Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000

Example 3:
Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.

Constraints:
    2 <= n <= 10^4
    0 <= start, end < n
    start != end
    0 <= a, b < n
    a != b
    0 <= succProb.length == edges.length <= 2*10^4
    0 <= succProb[i] <= 1
    There is at most one edge between every two nodes.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Intuition
    We use dijkstra's algo to find out the max probability from start node to end node . We use priority queue(max heap) to traverse the nodes ,keep the max probability on top and maintain an array to store the probability

Approach
    1. We create an adjacency list where each vertice stores the neighboring node and their corrosponding probability

    2. Create a max heap

    3. Push the starting node in the heap , and probability of start node to start node is one

    4. Traversal of priority qeue :

        . Extract the probability and node from the top of heap
        . Now loop over the neighboring nodes of node
        . Now do the same step as we did in step 1
        . Calculate the new probability as neigh_prob * node_prob
        . and check if it's greater than prob[neigh_prob]
        . if it's greater , then update and push it in queue to check further
        . Return the probabilty of end node

Complexity
    Time complexity:O(n+m.logn)
    Space complexity:O(n+m)
*/
class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<double> prob(n + 1, 0.0);      // probability array of all the vertices - initially 0
        vector<pair<int, double>> adj[n + 1]; // adjacency list

        // creation of adjacency list
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double, int>> pq;

        // pushing the starting node and prob of going from start node to start node is obviously 1
        pq.push({1.0, start});

        // prob of going from start node to start node is obviously 1
        prob[start] = 1.0;

        while (!pq.empty())
        {
            int node = pq.top().second;        // node
            double node_prob = pq.top().first; // probabilty of that node

            pq.pop();

            // travelling the neighboring nodes
            for (auto it : adj[node])
            {
                int neigh_node = it.first;     // neighboring node
                double neigh_prob = it.second; // probability of going from node to neighboring node

                double new_prob = neigh_prob * node_prob; // new probability - multiplication of the all the other paths to reach this neighboring node

                // checking if it's larger than the already present then we update it and we travel further
                if (prob[neigh_node] < new_prob)
                {
                    prob[neigh_node] = new_prob;
                    pq.push({prob[neigh_node], neigh_node});
                }
            }
        }

        // return the probability of going to the end node'
        return prob[end];
    }
};