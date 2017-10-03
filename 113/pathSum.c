#include <leetcode.h>

static int stackSize;
static struct TreeNode **stack;
int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize)
{
	struct TreeNode *node;
	int **paths, pathsSize, pathsIndex, top;

	top = 0;
	node = root;
	paths = NULL;
	pathsSize = 0;
	pathsIndex = 0;
	*columnSizes = NULL;
	*returnSize = 0;

	if (!root)
		return NULL;

	while (1) {
		if (top >= stackSize) {
			stackSize = ((!stackSize) ? 1 : (stackSize << 1));
			stack = realloc(stack, sizeof(*stack) * stackSize);
		}
		stack[top++] = node;
		sum -= node->val;

		if (node->left) {
			node = node->left;
			continue;
		} else if (node->right) {
			node = node->right;
			continue;
		}

		if (!sum) {
			if (pathsIndex >= pathsSize) {
				pathsSize = ((!pathsSize) ? 1 : (pathsSize << 1));
				paths = realloc(paths, sizeof(*paths) * pathsSize);
				*columnSizes = realloc(*columnSizes, sizeof(**columnSizes) * pathsSize);
			}

			paths[pathsIndex] = malloc(sizeof(**paths) * top);
			(*columnSizes)[pathsIndex] = top;
			for (int i = 0; i < top; ++i)
				paths[pathsIndex][i] = stack[i]->val;
			++pathsIndex;
		}

		while (--top) {
			sum += stack[top]->val;
			if (stack[top - 1]->right && stack[top - 1]->right != stack[top]) {
				node = stack[top - 1]->right;
				break;
			}
		}
		if (!top)
			break;
	}

	*returnSize = pathsIndex;

	return paths;
}

void tc_0(void)
{
	struct TreeNode t[] = {
		{5,&t[1],&t[2]},
		{4,&t[3],NULL},
		{8,&t[4],&t[5]},
		{11,&t[6],&t[7]},
		{13,NULL,NULL},
		{4,&t[8],&t[9]},
		{7,NULL,NULL},
		{2,NULL,NULL},
		{5,NULL,NULL},
		{1,NULL,NULL}
	};
	int **paths, *columnSizes, returnSize;
	paths = pathSum(t, 22, &columnSizes, &returnSize);
	for (int i = 0; i < returnSize; ++i) {
		for (int j = 0; j < columnSizes[i]; ++j) {
			if (j)
				printf(",");
			printf("%d", paths[i][j]);
		}
		free(paths[i]);
		printf("\n");
	}
	free(paths);
	free(columnSizes);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

