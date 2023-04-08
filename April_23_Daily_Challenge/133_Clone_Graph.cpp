/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed).
For example, the first node with val == 1, the second node with val == 2, and so on.
The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

Example 1:
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

Example 2:
Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.

Example 3:
Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.

Constraints:
    The number of nodes in the graph is in the range [0, 100].
    1 <= Node.val <= 100
    Node.val is unique for each node.
    There are no repeated edges and no self-loops in the graph.
    The Graph is connected and all nodes can be visited starting from the given node.
*/

#include <bits/stdc++.h>
using namespace std;

/* Definition for a Node. */
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution_DFS
{
public:
    // key is a node in the original graph and its value is the node’s copy
    unordered_map<Node *, Node *> copies;
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;

        if (copies.find(node) == copies.end()) // if node already not cloned/copied
        {
            copies[node] = new Node(node->val, {}); // copy it
            for (Node *neighbor : node->neighbors)
                copies[node]->neighbors.push_back(cloneGraph(neighbor)); // go to neighbors of actual Node to mark it clone neighbors of clone Node.
        }
        return copies[node];
    }
};

class Solution_BFS
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return NULL;

        unordered_map<Node *, Node *> copies;
        Node *copy = new Node(node->val, {});
        copies[node] = copy;
        queue<Node *> todo;
        todo.push(node);
        while (!todo.empty())
        {
            Node *cur = todo.front();
            todo.pop();
            for (Node *neighbor : cur->neighbors)
            {
                if (copies.find(neighbor) == copies.end())
                {
                    copies[neighbor] = new Node(neighbor->val, {});
                    todo.push(neighbor);
                }
                copies[cur]->neighbors.push_back(copies[neighbor]);
            }
        }
        return copy;
    }
};