#include <leetcode.h>

bool isSymmetric(struct TreeNode* root)
{
#define STKSZ 5000
	struct TreeNode *stack[STKSZ];
	int i, j, k, count, start, end;

	if (!root)
		return true;

	if (!root->left && !root->right)
		return true;
	else if (!root->left || !root->right)
		return false;

	count = 0;
	stack[count++] = root->left;
	stack[count++] = root->right;
	start = 0;
	end = count - 1;

	while (count) {
		for (i = start, j = end, k = 0; i < j; i++, j--) {
			if (stack[i]->val != stack[j]->val)
				return false;
			if (stack[i]->left) {
				if  (!stack[j]->right)
					return false;
				k += 2;
			} else if (!stack[i]->left && stack[j]->right) {
				return false;
			}
			if (stack[i]->right) {
				if (!stack[j]->left)
					return false;
				k += 2;
			} else if (!stack[i]->right && stack[j]->left) {
				return false;
			}
		}

		if (!k)
			break;

		j = end + 1;
		if (j + k >= STKSZ)
			j = 0;

		for (i = start; i <= end; i++) {
			if (stack[i]->left)
				stack[j++] = stack[i]->left;
			if (stack[i]->right)
				stack[j++] = stack[i]->right;
		}

		start = end + 1;
		end = j - 1;
		count = k;
	}

	return true;
}


