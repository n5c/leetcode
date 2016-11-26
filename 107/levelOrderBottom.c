#include <leetcode.h>

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize)
{
	int depth, i, j, count, **level;
	struct TreeNode ***_level;
	int treeDepth(struct TreeNode *root) {
		int left = 0, right = 0;
		if (!root)
			return 0;
		if (root->left)
			left = treeDepth(root->left);
		if (root->right)
			right = treeDepth(root->right);
		return (1 + ((left > right) ? left : right));
	}

	if (!root)
		return NULL;

	depth = treeDepth(root);
	*returnSize = depth;

	level = malloc(sizeof(*level) * depth);
	_level = malloc(sizeof(*_level) * depth);
	_level[0] = malloc(sizeof(**_level) * 1);
	_level[0][0] = root;

	*columnSizes = malloc(sizeof(**columnSizes) * depth);
	(*columnSizes)[0] = 1;

	for (i = 0; i < depth - 1; i++) {
		for (j = 0, count = 0; j < (*columnSizes)[i]; j++) {
			if (_level[i][j]->left)
				count++;
			if (_level[i][j]->right)
				count++;
		}
		_level[i + 1] = malloc(sizeof(**_level) * count);
		(*columnSizes)[i + 1] = count;
		for (j = 0, count = 0; j < (*columnSizes)[i]; j++) {
			if (_level[i][j]->left)
				_level[i + 1][count++] = _level[i][j]->left;
			if (_level[i][j]->right)
				_level[i + 1][count++] = _level[i][j]->right;
		}
	}

	for (i = 0; i < depth; i++) {
		level[i] = malloc(sizeof(**level) * (*columnSizes)[i]);
		for (j = 0; j < (*columnSizes)[i]; j++)
			level[i][j] = _level[i][j]->val;
		free(_level[i]);
	}
	free(_level);

	for (i = 0, j = depth - 1; i < j; i++, j--) {
		int *ptmp, tmp;
		ptmp = level[i];
		level[i] = level[j];
		level[j] = ptmp;

		tmp = (*columnSizes)[i];
		(*columnSizes)[i] = (*columnSizes)[j];
		(*columnSizes)[j] = tmp;
	}

	return level;
}

void printLevel(int **level, int *columnSizes, int size)
{
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < columnSizes[i]; j++) {
			printf("%d", level[i][j]);
			if (j + 1 < columnSizes[i])
				printf(",");
		}
		printf("\n");
	}
	printf("\n");
}

void tc_0()
{
	struct TreeNode t[] = {
		{ 3,&t[1],&t[2]},
		{ 9, NULL, NULL},
		{20,&t[3],&t[4]},
		{15, NULL, NULL},
		{ 7, NULL, NULL}
	};
	int i, **level, *columnSizes, size;

	level = levelOrderBottom(t, &columnSizes, &size);
	printLevel(level, columnSizes, size);
	for (i = 0; i < size; i++)
		free(level[i]);
	free(level);
	free(columnSizes);
}

void tc_1()
{
	struct TreeNode t[] = {
		{ 3,&t[1],&t[2]},
		{ 9, NULL, NULL},
		{20,&t[3],&t[4]},
		{15,&t[5],&t[6]},
		{ 7, NULL, NULL},
		{11,&t[7], NULL},
		{12, NULL,&t[8]},
		{13, NULL, NULL},
		{14, NULL, NULL}
	};
	int i, **level, *columnSizes, size;

	level = levelOrderBottom(t, &columnSizes, &size);
	printLevel(level, columnSizes, size);
	for (i = 0; i < size; i++)
		free(level[i]);
	free(level);
	free(columnSizes);
}

void tc_2()
{
	struct TreeNode t[] = {
		{ 0,&t[1],&t[2]},
		{ 2,&t[3], NULL},
		{ 4,&t[4],&t[5]},
		{ 1,&t[6],&t[7]},
		{ 3, NULL,&t[8]},
		{-1, NULL,&t[9]},
		{ 5, NULL, NULL},
		{ 1, NULL, NULL},
		{ 6, NULL, NULL},
		{ 8, NULL, NULL}
	};
	int i, **level, *columnSizes, size;

	level = levelOrderBottom(t, &columnSizes, &size);
	printLevel(level, columnSizes, size);
	for (i = 0; i < size; i++)
		free(level[i]);
	free(level);
	free(columnSizes);
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	tc_2();
	return 0;
}

