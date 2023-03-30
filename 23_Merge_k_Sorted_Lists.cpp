/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []

Constraints:
    k == lists.length
    0 <= k <= 10^4
    0 <= lists[i].length <= 500
    -10^4 <= lists[i][j] <= 10^4
    lists[i] is sorted in ascending order.
    The sum of lists[i].length will not exceed 10^4.
*/

#include <bits/stdc++.h>
using namespace std;

/** Definition for singly-linked list. */
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
    ListNode *merge(ListNode *left, ListNode *right)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        while (left != nullptr && right != nullptr)
        {
            if (left->val < right->val)
            {
                temp->next = left;
                temp = temp->next;
                left = left->next;
            }
            else
            {
                temp->next = right;
                temp = temp->next;
                right = right->next;
            }
        }
        while (left != nullptr)
        {
            temp->next = left;
            temp = temp->next;
            left = left->next;
        }

        while (right != nullptr)
        {
            temp->next = right;
            temp = temp->next;
            right = right->next;
        }
        return dummy->next;
    }

    ListNode *mergeSort(vector<ListNode *> &lists, int start, int end)
    {
        if (start == end)
            return lists[start];
        int mid = start + (end - start) / 2;
        ListNode *left = mergeSort(lists, start, mid);
        ListNode *right = mergeSort(lists, mid + 1, end);
        return merge(left, right);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;
        return mergeSort(lists, 0, lists.size() - 1);
    }
};