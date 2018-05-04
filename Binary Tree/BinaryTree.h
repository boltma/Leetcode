#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int x) : val (x), left (nullptr), right (nullptr) {}
};

struct TreeLinkNode
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode (int x) : val (x), left (nullptr), right (nullptr), next (nullptr) {}
};
#endif