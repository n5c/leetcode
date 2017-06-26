#include <leetcode.h>

static inline struct TreeNode *createNode(int val)
{
	struct TreeNode *node;
	node = malloc(sizeof(*node));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
	struct TreeNode *node, *left, *right;
	int i;

	if (!nums || !numsSize)
		return NULL;

	i = ((numsSize - 1) >> 1);
	node = createNode(nums[i]);

	left = NULL;
	if (i > 0) {
		left = sortedArrayToBST(nums, i);
	}

	right = NULL;
	if (i + 1 < numsSize) {
		right = sortedArrayToBST(&nums[i + 1], (numsSize - i - 1));
	}

	node->left = left;
	node->right = right;
	return node;
}

void tc_0(void)
{
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

