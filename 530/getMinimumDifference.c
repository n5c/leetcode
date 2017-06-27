#include <leetcode.h>

int getMinDiff(struct TreeNode *root, int *min, int *max)
{
	int diff, mindiff, _min, _max;

	if (!root || !min || !max)
		return INT_MAX;

	mindiff = INT_MAX;

	if (root->left) {
		_min = INT_MAX;
		_max = INT_MIN;
		diff = getMinDiff(root->left, &_min, &_max);
		if (diff < mindiff)
			mindiff = diff;

		diff = root->val - _max;
		if (diff < mindiff)
			mindiff = diff;

		if (_min < *min)
			*min = _min;
	}

	if (root->right) {
		_min = INT_MAX;
		_max = INT_MIN;
		diff = getMinDiff(root->right, &_min, &_max);
		if (diff < mindiff)
			mindiff = diff;

		diff = _min - root->val;
		if (diff < mindiff)
			mindiff = diff;

		if (_max > *max)
			*max = _max;
	}

	if (root->val < *min)
		*min = root->val;

	if (root->val > *max)
		*max = root->val;

	return mindiff;
}

int getMinimumDifference(struct TreeNode* root) {
	int min = INT_MAX, max = INT_MIN;
	return getMinDiff(root, &min, &max);
}

void tc_0(void)
{
	struct TreeNode t[] = {
		{1, NULL, &t[1]},
		{3, &t[2], NULL},
		{2, NULL, NULL}
	};
	printf("1 : %d\n", getMinimumDifference(&t[0]));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

