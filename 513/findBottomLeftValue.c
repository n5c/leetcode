#include <leetcode.h>

int findBottomLeftValueAndDepth(struct TreeNode *root, int *depth)
{
	int leftv, leftd, rightv, rightd;
	if (!root) {
		*depth = 0;
		return -1;

	}
	leftv = findBottomLeftValueAndDepth(root->left, &leftd);
	if (leftd == 0)
		leftv = root->val;
	rightv = findBottomLeftValueAndDepth(root->right, &rightd);
	if (rightd > leftd) {
		*depth = rightd + 1;
		return rightv;

	}
	*depth = leftd + 1;
	return leftv;

}
int findBottomLeftValue(struct TreeNode* root)
{
	int depth;
	return findBottomLeftValueAndDepth(root, &depth);

}

void tc_0(void)
{
	struct TreeNode t[] = {
		{2,&t[1],&t[2]},
		{1,NULL,NULL},
		{3,NULL,NULL},
	};
	printf("1\n%d\n\n",
		findBottomLeftValue(&t[0]));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

