#include <leetcode.h>

int diameter(struct TreeNode *root, int *radius)
{
	int d, dmax, rleft, rright;

	if (!root || !radius)
		return 0;

	dmax = 0;
	rleft = 0;
	if (root->left) {
		d = diameter(root->left, &rleft);
		if (d > dmax)
			dmax = d;
	}

	rright = 0;
	if (root->right) {
		d = diameter(root->right, &rright);
		if (d > dmax)
			dmax = d;
	}

	d = rleft + rright;
	if (d > dmax)
		dmax = d;

	*radius = (rleft > rright) ? rleft : rright;
	*radius += 1;

	return dmax;
}

int diameterOfBinaryTree(struct TreeNode* root)
{
	int r;
	return diameter(root, &r);
}

void tc_0(void)
{
	struct TreeNode t[] = {
		{1, &t[1], &t[2]},
		{2, &t[3], &t[4]},
		{3, NULL, NULL},
		{4, NULL, NULL},
		{5, NULL, NULL},
	};
	printf("3\n%d\n", diameterOfBinaryTree(t));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

