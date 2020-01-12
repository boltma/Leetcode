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
	vector<int> postorderTraversal (TreeNode *root)
	{
		if (root == nullptr)
			return vector<int>();
		vector<int> v{root->val}, v1 = postorderTraversal (root->left),
		                          v2 = postorderTraversal (root->right);
		v.insert (v.begin(), v2.begin(), v2.end());
		v.insert (v.begin(), v1.begin(), v1.end());
		return v;
	}
	*/
	/*
	typedef pair<bool, TreeNode *> elem;
	vector<int> postorderTraversal(TreeNode* root)
	{
		stack<elem> s;
		vector<int> v;
		while (root || !s.empty())
		{
			if (root)
			{
				s.push({true, root});
				root = root->left;
			}
			else
			{
				root = s.top().second;
				if (s.top().first)
				{
					s.top().first = false;
					root = root->right;
				}
				else
				{
					v.push_back(root->val);
					s.pop();
					root = nullptr;
				}

			}
		}
		return v;
	}
	*/
	vector<int> postorderTraversal(TreeNode * root)
	{
		vector<int> v;
		postorderTraversal(root, v);
		return v;
	}
	void postorderTraversal(TreeNode * root, vector<int> &v)
	{
		if (root == nullptr)
			return;
		postorderTraversal(root->left, v);
		postorderTraversal(root->right, v);
		v.push_back(root->val);
		return;
	}
};