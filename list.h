#ifndef LIST_H
#define LIST_H

struct ListNode
{
	int val;
	ListNode *next;
	ListNode (int x) : val (x), next (nullptr) {}
};
#endif