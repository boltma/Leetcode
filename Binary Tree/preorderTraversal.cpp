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
	vector<int> preorderTraversal (TreeNode *root)
	{
		if (root == nullptr)
			return vector<int>();
		vector<int> v{root->val}, v1 = preorderTraversal (root->left),
		                          v2 = preorderTraversal (root->right);
		v.insert (v.end(), v1.begin(), v1.end());
		v.insert (v.end(), v2.begin(), v2.end());
		return v;
	}
	*/
	/*
	vector<int> preorderTraversal(TreeNode* root)
	{
		stack<TreeNode *> s;
		vector<int> v;
		while (root)
		{
			v.push_back(root->val);
			if (root->right)
				s.push(root->right);
			if (root->left)
				root = root->left;
			else
			{
				if (!s.empty())
				{
					root = s.top();
					s.pop();
				}
				else
					root = nullptr;
			}
		}
		return v;
	}
	*/
	/*
	vector<int> preorderTraversal(TreeNode* root)
	{
		stack<TreeNode *> s;
		vector<int> v;
		while (root || !s.empty())
		{
			if (root)
			{
				s.push(root);
				v.push_back(root->val);
				root = root->left;
			}
			else
			{
				root = s.top()->right;
				s.pop();
			}
		}
		return v;
	}
	*/
	vector<int> preorderTraversal(TreeNode *root)
	{
		vector<int> v;
		preorderTraversal(root, v);
		return v;
	}
	void preorderTraversal(TreeNode *root, vector<int> &v)
	{
		if (root == nullptr)
			return;
		v.push_back(root->val);
		preorderTraversal(root->left, v);
		preorderTraversal(root->right, v);
		return;
	}
};