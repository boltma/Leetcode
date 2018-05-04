#include "BinaryTree.h"
#include <stack>
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

//Recursive version
class Solution
{
public:
	bool isSymmetric (TreeNode *root1, TreeNode *root2)
	{
		if (root1 == nullptr && root2 == nullptr)
			return true;
		if (root1 == nullptr || root2 == nullptr || root1->val != root2->val)
			return false;
		return isSymmetric (root1->left, root2->right) && isSymmetric (root1->right, root2->left);
	}
	bool isSymmetric (TreeNode *root)
	{
		return isSymmetric (root, root);
	}
};

/**
 * Loop version
 * class Solution
 * {
 * public:
 * 		bool isSymmetric (TreeNode *root)
 *		{
 *			if (root == nullptr || root->left == nullptr && root->right == nullptr)
 *				return true;
 *			if (root->left == nullptr || root->right == nullptr)
 *				return false;
 *			stack<TreeNode*> s1, s2;
 *			TreeNode *l = root->left, *r = root->right;
 *			while (l != nullptr || r != nullptr)
 *			{
 *				if (l == nullptr || r == nullptr || l->val != r->val)
 *					return false;
 *				if (l->right != nullptr)
 *				{
 *					if (r->left == nullptr)
 *						return false;
 *					s1.push (l->right);
 *					s2.push (r->left);
 *				}
 *				else
 *				{
 *					if (r->left != nullptr)
 *						return false;
 *				}
 *				l = l->left;
 *				r = r->right;
 *				if (l == nullptr && r == nullptr)
 *				{
 *					if (!s1.empty() && !s2.empty())
 *					{
 *						if (s1.empty() || s2.empty())
 *							return false;
 *						l = s1.top();
 *						r = s2.top();
 *						s1.pop();
 *						s2.pop();
 *					}
 *				}
 *			}
 *			return true;
 *		}
 *	};
 */