/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

Constraints:
    The number of nodes in the list is in the range [1, 5 * 10^4].
    1 <= Node.val <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

/*
  Definition for singly-linked list.
*/
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
    ListNode *mergeLL(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode *head = l1;
        l1 = l1->next;
        ListNode *p = head;

        bool flag = true;
        while (l1 && l2)
        {
            if (flag == false)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
            flag = !flag;
        }
        if (l1)
            p->next = l1;
        if (l2)
            p->next = l2;

        return head;
    }

    ListNode *reverseLL(ListNode *head)
    {
        if (head == NULL)
            return NULL;

        ListNode *h1 = head;
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

    void reorderList(ListNode *head)
    {
        int sz = 0;
        ListNode *tmp = head;
        while (tmp)
        {
            sz++;
            tmp = tmp->next;
        }
        assert(sz <= 1e6);

        // if(head == NULL || head->next == NULL || head->next->next == NULL)
        //     return head;

        // Find the mid of the LL that will be first mid of the LL, and split into two lists.
        ListNode *slow = head, *fast = head;

        while (slow != NULL && fast != NULL && fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *mid = slow->next;
        slow->next = NULL;

        // reverse from the middle to the end
        ListNode *secondHalfHead = reverseLL(mid);

        // merge two lists
        mergeLL(head, secondHalfHead);
    }
};