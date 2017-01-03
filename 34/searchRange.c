#include <leetcode.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
	int i, j, k, l, m;
	int *range;

	*returnSize = 2;
	range = malloc(sizeof(*range) * (*returnSize));

	i = 0;
	j = numsSize - 1;
	while (i <= j) {
		m = (i + j) >> 1;
		if (nums[m] == target)
			break;
		else if (nums[m] > target)
			j = m - 1;
		else /* if (nums[m] < target */
			i = m + 1;
	}

	if (nums[m] != target) {
		range[0] = -1;
		range[1] = -1;
		return range;
	}

	k = m + 1;
	l = j;

	j = m - 1;
	while (i <= j) {
		m = (i + j) >> 1;
		if (nums[m] == target)
			j = m - 1;
		else
			i = m + 1;
	}

	if (nums[m] != target)
		m++;
	range[0] = m;

	i = k;
	j = l;
	while (i <= j) {
		m = (i + j) >> 1;
		if (nums[m] == target)
			i = m + 1;
		else
			j = m - 1;
	}

	if (nums[m] != target)
		m--;
	range[1] = m;

	return range;
}

void tc_0(void)
{
	int nums[] = {5, 7, 7, 8, 8, 10};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int target = 8;
	int returnSize, *range;
	range = searchRange(nums, numsSize, target, &returnSize);
	printf("3,4\n");
	printf("%d,%d\n\n", range[0], range[1]);
	free(range);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

