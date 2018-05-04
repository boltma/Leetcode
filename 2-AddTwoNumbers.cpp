#include "list.h"

/**
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example:
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution
{
public:
	ListNode* addTwoNumbers (ListNode* l1, ListNode* l2)
	{
		int sum;
		bool flag;
		ListNode *prehead = new ListNode (0);
		ListNode *l = prehead;
		while (l1 != nullptr || l2 != nullptr || flag)
		{
			int x1 = l1 != nullptr ? l1->val : 0,
			    x2 = l2 != nullptr ? l2->val : 0;
			sum = flag + x1 + x2;
			flag = sum >= 10;
			l->next = new ListNode (sum % 10);
			l = l->next;
			if (l1 != nullptr)
				l1 = l1->next;
			if (l2 != nullptr)
				l2 = l2->next;
		}
		return prehead->next;
	}
};