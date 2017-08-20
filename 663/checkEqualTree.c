#include <leetcode.h>

static bool check;
static long long sum;
long long findSum(struct TreeNode *root)
{
	if (!root)
		return 0;
	return root->val + findSum(root->left) + findSum(root->right);

}
long long findEqual(struct TreeNode *root)
{
	long long left = 0, right = 0;
	if (!root || check)
		return 0;
	if (root->left) {
		left = findEqual(root->left);
		if (left == sum - left) {
			check = true;
			return 0;

		}

	}
	if (root->right) {
		right = findEqual(root->right);
		if (right == sum - right) {
			check = true;
			return 0;

		}

	}
	return (root->val + left + right);

}
bool checkEqualTree(struct TreeNode* root)
{
	sum = findSum(root);
	check = false;
	findEqual(root);
	return check;

}

void tc_0(void)
{
	struct TreeNode t[] = {
		{1,&t[1],&t[2]},
		{2,NULL,NULL},
		{10,&t[3],&t[4]},
		{2,NULL},
		{20,NULL},
	};
	printf("false\n%s\n\n", checkEqualTree(t) ? "true" : "false");
}

void tc_1(void)
{
	struct TreeNode t[] = {
		{0,NULL,&t[1]},
		{0,NULL,NULL},
	};
	printf("true\n%s\n\n", checkEqualTree(t) ? "true" : "false");
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	return 0;
}

