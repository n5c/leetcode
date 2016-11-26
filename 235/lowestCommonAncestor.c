#include <stdio.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
	struct TreeNode *left = NULL, *right = NULL;

	if (!root)
		return NULL;

	if (root == p || root == q)
		return root;

	if (root->left) {
		if (root->left == p || root->left == q)
			left = root->left;
		else
			left  = lowestCommonAncestor(root->left,  p, q);
	}

	if (root->right) {
		if (root->right == p || root->right == q)
			right = root->right;
		else
			right = lowestCommonAncestor(root->right, p, q);
	}

	if (right) {
		if (left)
			return root;
		return right;
	}

	return left;
}

void test_case_0(void)
{
	struct TreeNode t[] = {
		{6, &t[1], &t[2]},
		{2, &t[3], &t[4]},
		{8, &t[5], &t[6]},
		{0, NULL,NULL },
		{4, &t[7], &t[8]},
		{7, NULL,NULL},
		{9, NULL,NULL},
		{3, NULL,NULL},
		{5, NULL,NULL},
	};
	struct TreeNode *node;
	printf("...\n");
	printf("2\n");
	node = lowestCommonAncestor(t, &t[1], &t[4]);
	printf("%d\n\n", node->val);

	printf("...\n");
	printf("6\n");
	node = lowestCommonAncestor(t, &t[1], &t[2]);
	printf("%d\n\n", node->val);

	printf("...\n");
	printf("2\n");
	node = lowestCommonAncestor(t, &t[7], &t[1]);
	printf("%d\n\n", node->val);

	printf("...\n");
	printf("2\n");
	node = lowestCommonAncestor(t, &t[8], &t[3]);
	printf("%d\n\n", node->val);
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

