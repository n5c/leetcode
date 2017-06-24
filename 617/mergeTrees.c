#include <leetcode.h>

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2)
{
	struct TreeNode *node, *l1, *l2, *r1, *r2;

	if (!t1 && !t2)
		return NULL;

	node = calloc(1, sizeof(*node));

	l1 = NULL;
	r1 = NULL;
	if (t1) {
		node->val += t1->val;
		l1 = t1->left;
		r1 = t1->right;
	}

	l2 = NULL;
	r2 = NULL;
	if (t2) {
		node->val += t2->val;
		l2 = t2->left;
		r2 = t2->right;
	}

	node->left  = mergeTrees(l1, l2);
	node->right = mergeTrees(r1, r2);

	return node;
}

void tc_0(void)
{
	struct TreeNode *node;
	struct TreeNode t1[] = {
		{1,&t1[1],&t1[2]},
		{3,&t1[3],NULL},
		{2,NULL,NULL},
		{5,NULL,NULL},
	};
	struct TreeNode t2[] = {
		{2,&t2[1],&t2[2]},
		{1,NULL,&t2[3]},
		{3,NULL,&t2[4]},
		{4,NULL,NULL},
		{7,NULL,NULL}
	};

	//node = mergeTrees(&t1, &t2);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

