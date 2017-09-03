#include <leetcode.h>

struct TreeNode* trimBST(struct TreeNode* root, int L, int R)
{
	if (!root)
		return NULL;
	if (root->val < L)
		return trimBST(root->right, L, R);
	if (root->val > R)
		return trimBST(root->left, L, R);
	root->left = trimBST(root->left, L, R);
	root->right = trimBST(root->right, L, R);
	return root;
}

void tc_0(void)
{
	struct TreeNode t[] = {
		{5,&t[1],&t[2]},
		{2,&t[3],&t[4]},
		{7,&t[5],&t[6]},
		{1,NULL,NULL},
		{3,NULL,&t[7]},
		{6,NULL,NULL},
		{8,NULL,NULL},
		{4,NULL,NULL},
	};
	trimBST(t, 4, 6);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

