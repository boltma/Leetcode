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
class Solution
{
public:
	/*
	vector<int> inorderTraversal (TreeNode *root)
	{
		if (root == nullptr)
			return vector<int>();
		vector<int> v{root->val}, v1 = inorderTraversal (root->left),
		                          v2 = inorderTraversal (root->right);
		v.insert (v.begin(), v1.begin(), v1.end());
		v.insert (v.end(), v2.begin(), v2.end());
		return v;
	}
	*/
	vector<int> inorderTraversal (TreeNode *root)
	{
		vector<int> v;
		inorderTraversal (root, v);
		return v;
	}
	void inorderTraversal (TreeNode *root, vector<int> &v)
	{
		if (root == nullptr)
			return;
		inorderTraversal (root->left, v);
		v.push_back (root->val);
		inorderTraversal (root->right, v);
		return;
	}
};