#include <stdio.h>

#define bool int
#define true 1
#define false 2

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isBalanced(struct TreeNode* root)
{
	int treeHeight(struct TreeNode *_root) {
		int _left = 0, _right = 0;
		if (!_root)
			return 0;
		if (_root->left) {
			_left = treeHeight(_root->left);
			if (_left == -1)
				return -1;
		}
		if (_root->right) {
			_right = treeHeight(_root->right);
			if (_right == -1)
				return -1;
		}
		if ((_left - _right >= 2) || (_right - _left >= 2))
			return -1;
		if (_left > _right)
			return 1 + _left;
		return 1 + _right;
	}
	if (!root)
		return true;
	if (treeHeight(root) == -1)
		return false;
	return true;
}


