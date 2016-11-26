/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int sumOfLeftLeaves(struct TreeNode* root) {
	int sum = 0;
	if (!root)
		return 0;
	if (root->left) {
		if (!root->left->left && !root->left->right)
			sum += root->left->val;
		else
			sum += sumOfLeftLeaves(root->left);
	}
	if (root->right && (root->right->left || root->right->right))
		sum += sumOfLeftLeaves(root->right);
	return sum;
}

