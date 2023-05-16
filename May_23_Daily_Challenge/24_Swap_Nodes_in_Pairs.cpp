/*
Given a linked list, swap every two adjacent nodes and return its head.
You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]

Constraints:
    The number of nodes in the list is in the range [0, 100].
    0 <= Node.val <= 100
*/

#include <bits/stdc++.h>
using namespace std;

/* Definition for singly-linked list.*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution_Iterative
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head; // If there are less than 2 nodes in the given nodes, then no need to do anything just return the list as it is.

        ListNode *dummyNode = new ListNode();

        ListNode *prevNode = dummyNode;
        ListNode *currNode = head;

        while (currNode && currNode->next)
        {
            prevNode->next = currNode->next;
            currNode->next = prevNode->next->next;
            prevNode->next->next = currNode;

            prevNode = currNode;
            currNode = currNode->next;
        }

        return dummyNode->next;
    }
};

class Solution_recursive
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *temp;    // temporary pointer to store head -> next
        temp = head->next; // give temp what he want

        head->next = swapPairs(head->next->next); // Changing links
        temp->next = head;                        // put temp -> next to head

        return temp; // now after changing links, temp act as our head
    }
};