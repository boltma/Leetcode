#include "BinaryTree.h"
using namespace std;

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
 * };
 */
class Solution
{
public:
	//Populate each next pointer to point to its next right node in a perfect binary tree.
	/*
	void connect (TreeLinkNode *root)
	{
		if (root == nullptr)
			return;
		root->next = nullptr;
		int k = 1;
		TreeLinkNode *p = root->left, *parent = root;
		while (p != nullptr)
		{
			TreeLinkNode *q = p, *r = parent;
			k <<= 1;
			for (int i = 0; i < k; ++i)
			{
				if (i % 2 == 1)
					r = r->next;
				if (r != nullptr)
					q->next = i % 2 == 1 ? r->left : r->right;
				else
					q->next = nullptr;
				q = q->next;
			}
			parent = p;
			p = p->left;
		}
		return;
	}
	*/
	//Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
	void connect (TreeLinkNode *root)
	{
		if (root == nullptr)
			return;
		root->next = nullptr;
		TreeLinkNode *p = root, *l;
		while (p != nullptr)
		{
			TreeLinkNode *t = p;
			bool is_left_child;
			while (t != nullptr)
			{
				l = t->left;
				if (l != nullptr)
				{
					is_left_child = true;
					break;
				}
				l = t->right;
				if (l != nullptr)
				{
					is_left_child = false;
					break;
				}
				t = t->next;
			}
			p = l;
			while (l != nullptr)
			{
				TreeLinkNode *r = nullptr;
				while (t != nullptr)
				{
					if (is_left_child)
					{
						r = t->right;
						is_left_child = false;
						if (r != nullptr)
							break;
					}
					else
					{
						t = t->next;
						if (t == nullptr)
							break;
						r = t->left;
						is_left_child = true;
						if (r != nullptr)
							break;
					}
				}
				l->next = r;
				l = r;
			}
		}
	}
};