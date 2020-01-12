#include "Binary Tree/BinaryTree.h"
#include <algorithm>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
	TreeNode* bstFromPreorder(vector<int>& preorder)
	{
		if (preorder.empty())
			return nullptr;
		TreeNode *root = new TreeNode(preorder[0]);
		auto it = upper_bound(preorder.begin(), preorder.end(), preorder[0]);
		vector<int> left(preorder.begin() + 1, it), right(it, preorder.end());
		root->left = bstFromPreorder(left);
		root->right = bstFromPreorder(right);
		return root;
	}
};