#include <leetcode.h>

static int track(struct TreeNode *root, int *max)
{
	int left = 0, right = 0, length = 0;
	if (!root)
		return 0;
	if (root->left) {
		left = track(root->left, max);
		if (root->left->val == root->val)
			++left;
		else
			left = 0;
	}
	if (root->right) {
		right = track(root->right, max);
		if (root->right->val == root->val)
			++right;
		else
			right = 0;
	}
	if (left + right > *max)
		*max = left + right;
	if (left > right)
		return left;
	return right;
}

int longestUnivaluePath(struct TreeNode* root)
{
	int max = 0;
	track(root, &max);
	return max;
}

void tc_0(void)
{
	struct TreeNode t[] = {
		{5,&t[1],&t[2]},
		{4,&t[3],&t[4]},
		{5,NULL,&t[5]},
		{1,NULL,NULL},
		{1,NULL,NULL},
		{5,NULL,NULL}
	};
	printf("2\n%d\n\n", longestUnivaluePath(t));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

