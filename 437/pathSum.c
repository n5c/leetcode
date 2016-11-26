#include <stdio.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int pathSum(struct TreeNode* root, int sum)
{
	int top, pathSum, count, i;
	struct TreeNode *node, *stack[1000];

	if (!root)
		return 0;

	node = root;
	top = 0;
	stack[0] = NULL;
	pathSum = 0;
	while (1) {
		stack[top++] = node;
		for (i = top - 1, count = 0; i >= 0; i--) {
			count += stack[i]->val;
			if (count == sum)
				pathSum++;
		}

		if (node->left) {
			node = node->left;
		} else if (node->right) {
			node = node->right;
		} else {
			while (1) {
				if (!top)
					break;
				if (stack[top - 1]->right &&
					stack[top - 1]->right != stack[top]) {
					node = stack[top - 1]->right;
					break;
				}
				top--;
			}
			if (!top)
				break;
		}
	}

	return pathSum;
}

void test_case_0()
{
	struct TreeNode t[] = {
		{10,&t[1],&t[2]},
		{ 5,&t[3],&t[4]},
		{-3, NULL,&t[5]},
		{ 3,&t[6],&t[7]},
		{ 2, NULL,&t[8]},
		{11, NULL, NULL},
		{ 3, NULL, NULL},
		{-2, NULL, NULL},
		{ 1, NULL, NULL},
	};
	printf("   3\n");
	printf("=> %d\n", pathSum(t, 8));
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

