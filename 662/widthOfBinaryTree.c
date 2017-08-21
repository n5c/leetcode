#include <leetcode.h>

struct mystack {
	int leftmost;
	int rightmost;
	struct TreeNode *node;

};
static int stackSize = 0;
static struct mystack *stack;
int widthOfBinaryTree(struct TreeNode* root)
{
	int i, j, index, level, width, maxWidth;
	struct TreeNode *node;

	if (!root)
		return 0;

	if (!stackSize) {
		stackSize = 1024;
		stack = realloc(NULL, sizeof(*stack) * stackSize);
	}

	i = 0;
	index = 1;
	level = -1;
	maxWidth = 1;
	node = root;
	while (1) {
		if (i >= stackSize) {
			stackSize <<= 1;
			stack = realloc(stack, sizeof(*stack) * stackSize);
		}
		if (i > level) {
			level = i;
			stack[i].leftmost = index;
			stack[i].rightmost = index;
		} else if (stack[i].rightmost < index) {
			stack[i].rightmost = index;
			width = stack[i].rightmost - stack[i].leftmost + 1;
			if (width > maxWidth)
				maxWidth = width;
		}
		stack[i++].node = node;

		if (node->left) {
			node = node->left;
			index = (index * 2);
		} else if (node->right) {
			node = node->right;
			index = (index * 2) + 1;
		} else {
			i--;
			while (i) {
				if (stack[i - 1].node->right && stack[i - 1].node->right != stack[i].node) {
					node = stack[i - 1].node->right;
					index++;
					break;
				}
				i--;
				index = (index / 2);
			}
			if (!i)
				break;
		}
	}

	return maxWidth;
}

void tc_0(void)
{
	struct TreeNode t[] = {
		{1,&t[1],&t[2]},
		{3,&t[3],NULL},
		{2,NULL,&t[4]},
		{5,&t[5],NULL},
		{9,NULL,&t[6]},
		{6,NULL,NULL},
		{7,NULL,NULL},
	};
	printf("8\n%d\n\n", widthOfBinaryTree(t));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

