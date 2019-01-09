#include "list.h"

/* Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 *
 * Example:
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode *head = new ListNode(0), *p = head;
		if (head == nullptr)
			return nullptr;
		while (l1 != nullptr && l2 != nullptr)
		{
			ListNode *q;
			if (l1->val > l2->val)
			{
				q = new ListNode(l2->val);
				l2 = l2->next;
			}
			else
			{
				q = new ListNode(l1->val);
				l1 = l1->next;
			}
			if (q == nullptr)
				return nullptr;
			p->next = q;
			p = q;
		}
		if (l1 == nullptr)
			p->next = l2;
		else p->next = l1;
		p = head->next;
		delete head;
		return p;
	}
};