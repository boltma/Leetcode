#include "BinaryTree.h"
#include <vector>
#include <queue>
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
	vector<vector<int> > levelOrder (TreeNode *root)
	{
		vector<vector<int> > v;
		queue<TreeNode *> q;
		if (root != nullptr)
			q.push (root);
		vector<int> w;
		TreeNode *p = root;
		while (!q.empty())
		{
			TreeNode *r = q.front();
			q.pop();
			w.push_back (r->val);
			if (r->left != nullptr)
				q.push (r->left);
			if (r->right != nullptr)
				q.push (r->right);
			if (r == p)
			{
				v.push_back (w);
				w.clear();
				p = q.back();
			}
		}
		return v;
	}
};