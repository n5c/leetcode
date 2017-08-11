#include <leetcode.h>

static void constructArray(struct TreeNode **stack, int index,
		char ***array, int row, int col, int start)
{
	int i, pos;
	char s[16];
	if (!stack[index])
		return;
	pos = col / 2;
	if (array[row][start + pos])
		free(array[row][start + pos]);
	snprintf(s, 16, "%d", stack[index]->val);
	array[row][start + pos] = strdup(s);
	constructArray(stack, ((index + 1) << 1) - 1, array, row + 1, col / 2, start);
	constructArray(stack, ((index + 1) << 1), array, row + 1, col / 2, start + pos + 1);

}

char*** printTree(struct TreeNode* root, int** columnSizes,
		int* returnSize)
{
	int i, j, k, l, m, n, row, col;
	char s[16], ***array;
	struct TreeNode *stack[2048];

	stack[0] = root;
	i = 0;
	j = 1;
	row = 0;
	col = 1;
	l = col;
	while (1) {
		k = 0;
		while (i < l) {
			if (!stack[i]) {
				stack[j++] = NULL;
				stack[j++] = NULL;
			} else {
				k = 1;
				stack[j++] = stack[i]->left;
				stack[j++] = stack[i]->right;
			}
			i++;
		}
		if (!k)
			break;
		col <<= 1;
		row++;
		l += col;
	}

	col--;
	*returnSize = row;
	array = malloc(sizeof(*array) * row);
	*columnSizes = malloc(sizeof(**columnSizes) * row);
	for (i = 0; i < row; i++) {
		array[i] = malloc(sizeof(**array) * col);
		for (j = 0; j < col; j++)
			array[i][j] = strdup("");
		(*columnSizes)[i] = col;
	}
	constructArray(stack, 0, array, 0, col, 0);

	return array;

}

void tc_0(void)
{
	struct TreeNode t[] = {
		{1,&t[1],NULL},
		{2,NULL,NULL}
	};
	int *columnSizes;
	int returnSize;
	char ***s = printTree(t, &columnSizes, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		for (int j = 0; j < columnSizes[i]; j++) {
			if (j)
				printf(",");
			if (!s[i][j])
				printf("\"\"");
			else
				printf("\"%s\"", s[i][j]);
			free(s[i][j]);
		}
		printf("\n");
		free(s[i]);
	}
	printf("\n");
	free(s);
	free(columnSizes);
}

void tc_1(void)
{
	struct TreeNode t[] = {
		{1,&t[1],&t[2]},
		{2,&t[3],NULL},
		{5,NULL,NULL},
		{3,&t[4],NULL},
		{4,NULL,NULL},
	};
	int *columnSizes;
	int returnSize;
	char ***s = printTree(t, &columnSizes, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		for (int j = 0; j < columnSizes[i]; j++) {
			if (j)
				printf(",");
			if (!s[i][j])
				printf("\"\"");
			else
				printf("\"%s\"", s[i][j]);
			free(s[i][j]);
		}
		printf("\n");
		free(s[i]);
	}
	printf("\n");
	free(s);
	free(columnSizes);
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	return 0;
}

