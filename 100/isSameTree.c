#include <leetcode.h>

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	bool b;

	if (!p && !q)
		return true;

	if (!p || !q)
		return false;

	if (p->val != q->val)
		return false;

	if ((p->left && !q->left) || (!p->left && q->left))
		return false;

	if ((p->right && !q->right) || (!p->right && q->right))
		return false;

	if (p->left && !isSameTree(p->left, q->left))
		return false;

	if (p->right && !isSameTree(p->right, q->right))
		return false;

	return true;
}

void tc_0(void)
{
	struct TreeNode p[] = {
		{0, &p[1], &p[2]},
		{1, NULL,  NULL},
		{2, NULL,  NULL}
	};
	struct TreeNode q[] = {
		{0, &q[1], &q[2]},
		{1, NULL,  NULL},
		{2, NULL,  NULL}
	};

	printf("true:\n");
	printf("%s\n", (isSameTree(p,q) ? "true" : "false"));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

