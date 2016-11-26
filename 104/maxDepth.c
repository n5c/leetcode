#include <leetcode.h>

int maxDepth(struct TreeNode* root)
{
	int l, r;

	if (root == NULL)
		return 0;

	l = maxDepth(root->left);
	r = maxDepth(root->right);
	if (l >= r)
		return (l + 1);
	else
		return (r + 1);
}

void tc_0(void)
{
	struct TreeNode t[] = {
		{ 0,   &t[1],   &t[2]},
		{ 1,   &t[3],    NULL},
		{ 2,    NULL,   &t[4]},
		{ 3,   &t[5],   &t[6]},
		{ 4,    NULL,   &t[7]},
		{ 5,   &t[8],    NULL},
		{ 6,   &t[9],  &t[10]},
		{ 7,    NULL,    NULL},
		{ 8,    NULL,    NULL},
		{ 9,  &t[11],  &t[12]},
		{10,  &t[13],  &t[14]},
		{11,    NULL,    NULL},
		{12,  &t[15],    NULL},
		{13,    NULL,  &t[16]},
		{14,    NULL,    NULL},
		{15,    NULL,    NULL},
		{16,  &t[17],    NULL},
		{17,    NULL,    NULL},
	};
	printf("8: %d\n", maxDepth(t));
}

void tc_1(void)
{
	struct TreeNode t[] = {
		{ 0,   &t[1],   &t[2]},
		{ 1,   &t[3],    NULL},
		{ 2,    NULL,   &t[4]},
		{ 3,   &t[5],   &t[6]},
		{ 4,    NULL,   &t[7]},
		{ 5,   &t[8],    NULL},
		{ 6,   &t[9],  &t[10]},
		{ 7,    NULL,    NULL},
		{ 8,    NULL,    NULL},
		{ 9,    NULL,  &t[11]},
		{10,    NULL,    NULL},
		{11,    NULL,    NULL},
	};
	printf("6: %d\n", maxDepth(t));
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	return 0;
}

