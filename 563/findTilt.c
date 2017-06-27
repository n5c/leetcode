#include <leetcode.h>

int findTilt2(struct TreeNode *root, int *sum)
{
	int left, right, tilt;

	if (!root || !sum)
		return 0;

	tilt = 0;
	left = 0;
	right = 0;
	if (root->left)
		tilt += findTilt2(root->left, &left);
	if (root->right)
		tilt += findTilt2(root->right, &right);
	*sum = root->val + left + right;
	tilt += abs(left - right);
	return tilt;
}

int findTilt(struct TreeNode* root)
{
	int sum;
	return findTilt2(root, &sum);
}

void tc_0(void)
{
	struct TreeNode t[] = {
		{1, &t[1], &t[2]},
		{2, NULL, NULL},
		{3, NULL, NULL}
	};
	printf("1\n%d\n", findTilt(t));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

