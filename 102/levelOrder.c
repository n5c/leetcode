#include <leetcode.h>

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize)
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

	return level;
}


