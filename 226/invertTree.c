#include <stdio.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root) {
	struct TreeNode *left, *right;

	if (!root)
		return NULL;

	left = ((root->left) ? invertTree(root->left) : NULL);
	right = ((root->right) ? invertTree(root->right) : NULL);
	root->left = right;
	root->right = left;

	return root;
}

