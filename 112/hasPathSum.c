#include <leetcode.h>

bool hasPathSum(struct TreeNode* root, int sum)
{
	int top;
	struct TreeNode *stack[1000], *node;

	if (!root)
		return false;

	node = root;
	top = 0;
	while (1) {
		stack[top++] = node;
		if (node->left) {
			node = node->left;
			continue;
		} else if (node->right) {
			node = node->right;
			continue;
		}

		int i, _sum;

		for (i = top - 1, _sum = 0; i >= 0; i--)
			_sum += stack[i]->val;
		if (sum == _sum)
			return true;
		while (top) {
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

	return false;
}

void tc_0(void)
{
	int sum = 22;
	struct TreeNode t[] = {
		{5,  &t[1], &t[2]},
		{4,  &t[3], NULL},
		{8,  &t[4], &t[5]},
		{11, &t[6], &t[7]},
		{13, NULL,  NULL},
		{14, NULL,  &t[8]},
		{7,  NULL,  NULL},
		{2,  NULL,  NULL},
		{1,  NULL,  NULL}
	};

	printf("true\n");
	printf("%s\n", (hasPathSum(&t[0], sum) ? "true" : "false"));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

