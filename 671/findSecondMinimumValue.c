#include <leetcode.h>

int first;
int second;
void find(struct TreeNode *root)
{
	if (!root)
		return;
	if (first == -1) {
		first = root->val;

	} else if (first < root->val) {
		if (second == -1 || second > root->val)
			second = root->val;
		return;

	}
	find(root->left);
	find(root->right);

}
int findSecondMinimumValue(struct TreeNode* root)
{
	if (!root)
		return -1;
	first = -1;
	second = -1;
	find(root);
	return second;

}

void tc_0(void)
{
	struct TreeNode t[] = {
		{2,&t[1],&t[2]},
		{2,NULL,NULL},
		{5,&t[3],&t[4]},
		{5,NULL,NULL},
		{7,NULL,NULL},
	};
	printf("5\n%d\n\n", findSecondMinimumValue(t));
}

void tc_1(void)
{
	struct TreeNode t[] = {
		{2,&t[1],&t[2]},
		{2,NULL,NULL},
		{2,NULL,NULL},
	};
	printf("-1\n%d\n\n", findSecondMinimumValue(t));
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	return 0;
}

