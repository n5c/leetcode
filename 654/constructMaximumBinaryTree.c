#include <leetcode.h>

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize)
{
	int i;
	struct TreeNode *node, *root;

	if (!numsSize)
		return NULL;

	root = calloc(1, sizeof(*root));
	root->val = nums[0];

	for (i = 1; i < numsSize; i++) {
		node = calloc(1, sizeof(*node));
		node->val = nums[i];
		if (node->val > root->val) {
			node->left = root;
			root = node;
		}
		struct TreeNode *_node = root;
		while (_node->right && (_node->right->val > node->val))
			_node = _node->right;
		node->left = _node->right;
		_node->right = node;
	}

	return root;
}

void tc_0(void)
{
	int nums[] = {3,2,1,6,0,5};
	int numsSize = sizeof(nums)/sizeof(*nums);
	struct TreeNode *root = constructMaximumBinaryTree(nums, numsSize);

	// TODO:
	// print TreeNode
	// free TreeNode
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

