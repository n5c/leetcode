#include <leetcode.h>

static struct TreeNode *_bsearch(struct TreeNode *root, int n)
{
	if (!root)
		return NULL;
	if (n == root->val)
		return root;
	if (n < root->val)
		return _bsearch(root->left, n);
	return _bsearch(root->right, n);
}
static bool _findTarget(struct TreeNode *root, struct TreeNode *node, int k)
{
	int n;
	struct TreeNode *_node;
	if (!root || !node)
		return false;
	n = k - node->val;
	if ((_node = _bsearch(root, n)) && (_node != node))
		return true;
	else if ((_node = _bsearch(root, n)) && (_node != node))
		return true;
	if (_findTarget(root, node->left, k))
		return true;
	return _findTarget(root, node->right, k);
}
bool findTarget(struct TreeNode* root, int k)
{
	return _findTarget(root, root, k);
}

void tc_0(void)
{
	struct TreeNode t[] = {
		{2,NULL,&t[1]},
		{3,NULL,NULL}
	};
	printf("false\n%s\n\n",
		findTarget(t, 6) ? "true" : "false");
}

void tc_1(void)
{
	struct TreeNode t[] = {
		{5,&t[1],&t[2]},
		{3,&t[3],&t[4]},
		{6,NULL,&t[5]},
		{2,NULL,NULL},
		{4,NULL,NULL},
		{7,NULL,NULL}
	};
	printf("true\n%s\n\n",
		findTarget(t, 9) ? "true" : "false");
	printf("false\n%s\n\n",
		findTarget(t, 28) ? "true" : "false");
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	return 0;
}

