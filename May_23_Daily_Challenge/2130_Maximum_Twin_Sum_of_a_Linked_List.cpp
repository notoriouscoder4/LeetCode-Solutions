/*
In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

    1. For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2.
    These are the only nodes with twins for n = 4.

The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.

Example 1:
Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6.

Example 2:
Input: head = [4,2,2,3]
Output: 7
Explanation:
The nodes with twins present in this linked list are:
- Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
Thus, the maximum twin sum of the linked list is max(7, 4) = 7.

Example 3:
Input: head = [1,100000]
Output: 100001
Explanation:
There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.

Constraints:
    The number of nodes in the list is an even integer in the range [2, 105].
    1 <= Node.val <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

/*Definition for singly-linked list.*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int pairSum(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        int maxVal = 0;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *nextNode, *prev = NULL;
        while (slow != NULL)
        {
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        while (prev != NULL)
        {
            maxVal = max(maxVal, head->val + prev->val);
            prev = prev->next;
            head = head->next;
        }
        return maxVal;
    }
};

class Solution
{
public:
    // Reversing the Linked List
    ListNode *reverseList(ListNode *head)
    {
        ListNode *h1 = head;
        if (h1 == NULL)
            return NULL;
        ListNode *h2 = NULL;
        ListNode *temp;
        while (h1 != NULL)
        {
            temp = h1;
            h1 = h1->next;
            temp->next = h2;
            h2 = temp;
        }
        return h2;
    }

    int pairSum(ListNode *head)
    {
        ListNode *nodeSlow = head, *nodeFast = head;
        int res = 0;

        // Getting the middle node
        while (nodeFast->next->next != NULL)
        {
            nodeFast = nodeFast->next->next;
            nodeSlow = nodeSlow->next;
        }
        nodeSlow->next = reverseList(nodeSlow->next);
        nodeFast = head;
        while (nodeSlow->next != NULL)
        {
            res = max(nodeFast->val + nodeSlow->next->val, res);
            nodeSlow = nodeSlow->next;
            nodeFast = nodeFast->next;
        }
        return res;
    }
};

/*
    TC: O(N)
    SC: O(N)
*/
class Solution_stack
{
public:
    int pairSum(ListNode *head)
    {
        ListNode *temp = head;
        stack<int> s;
        while (temp)
        {
            s.push(temp->val);
            temp = temp->next;
        }
        int mx = 0;
        while (s.size())
        {
            mx = max(mx, s.top() + head->val);
            head = head->next;
            s.pop();
        }
        return mx;
    }
};