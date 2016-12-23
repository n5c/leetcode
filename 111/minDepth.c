#include <leetcode.h>

int minDepth(struct TreeNode* root)
{
	int min, top, stackSize;
	struct TreeNode *node, **stack;

	stackSize = 1000;
	stack = malloc(sizeof(*stack) * stackSize);

	min = INT_MAX;
	top = 0;
	node = root;
	while (node) {
		stack[top++] = node;
		if (top >= stackSize) {
			stackSize += 1000;
			stack = realloc(stack, sizeof(*stack) * stackSize);
		}

		if (top < min) {
			if (node->left) {
				node = node->left;
				continue;
			} else if (node->right) {
				node = node->right;
				continue;
			}
		}

		if (top < min)
			min = top;

		top--;
		while (top) {
			if (stack[top - 1]->right && stack[top - 1]->right != stack[top]) {
				node = stack[top - 1]->right;
				break;
			}
			top--;
		}

		if (!top)
			break;
	}

	if (min == INT_MAX)
		min = 0;

	free(stack);

	return min;
}

void tc_0(void)
{
	struct TreeNode t[] = {
		{0,  NULL,  NULL}
	};
	printf("1\n");
	printf("%d\n", minDepth(&t[0]));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

