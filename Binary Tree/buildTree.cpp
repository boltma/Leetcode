#include "BinaryTree.h"
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

//assume that duplicates do not exist in the tree
class Solution
{
public:
	//Given inorder and postorder traversal of a tree, construct the binary tree.
	/*
	TreeNode* buildTree (vector<int> &inorder, vector<int> &postorder)
	{
		if (inorder.empty())
			return nullptr;
		vector<int>::iterator in = inorder.begin(), post = postorder.end() - 1;
		while (*in != *post)
			++in;
		int left_num = in - inorder.begin();
		post = postorder.begin() + left_num;
		TreeNode *root = new TreeNode (*in);
		vector<int> in_left (inorder.begin(), in), 	post_left (postorder.begin(), post),
		       in_right (in + 1, inorder.end()), 	post_right (post, postorder.end() - 1);
		root->left = buildTree (in_left, post_left);
		root->right = buildTree (in_right, post_right);
		return root;
	}
	*/
	/**************************************************
	TreeNode* buildTree (vector<int> &inorder, vector<int> &postorder)
	{
		if (inorder.empty())
			return nullptr;
		int size = inorder.size() - 1;
		return CreateTree (inorder, postorder, 0, size, size);
	}
	TreeNode* CreateTree (vector<int> &inorder, vector<int> &postorder, int start, int end, int &index)
	{
		int p = postorder[index];
		int i = end;
		while (inorder[i] != p)
			--i;
		TreeNode *root = new TreeNode (p);
		if (i < end)
			root->right = CreateTree (inorder, postorder, i + 1, end, --index);
		if (i > start)
			root->left = CreateTree (inorder, postorder, start, i - 1, --index);
		return root;
	};
	**************************************************/
	//Given preorder and inorder traversal of a tree, construct the binary tree.
	TreeNode* buildTree (vector<int> &preorder, vector<int> &inorder)
	{
		if (inorder.empty())
			return nullptr;
		int size = inorder.size() - 1;
		int index = 0;
		return CreateTree (preorder, inorder, 0, size, index);
	}
	TreeNode* CreateTree (vector<int> &preorder, vector<int> &inorder, int start, int end, int &index)
	{
		int p = preorder[index];
		int i = start;
		while (inorder[i] != p)
			++i;
		TreeNode *root = new TreeNode (p);
		if (start < i) //must perform this compare or index would add when we create a nullptr
			root->left = CreateTree (preorder, inorder, start, i - 1, ++index);
		if (end > i)
			root->right = CreateTree (preorder, inorder, i + 1, end, ++index);
		return root;
	};
};