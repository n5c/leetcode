#include <leetcode.h>

int *nums_base = NULL;

int cmp(const void *a, const void *b)
{
	int diff;

	diff = nums_base[*(int *)a] - nums_base[*(int *)b];
	if (diff)
		return diff;
	return *(int *)a - *(int *)b;
}
bool containsNearbyDuplicate(int* nums, int numsSize, int k)
{
	int i, j, *_nums;

	if (numsSize <= 1)
		return false;

	nums_base = nums;
	_nums = malloc(sizeof(*_nums) * numsSize);

	for (i = 0; i < numsSize; i++)
		_nums[i] = i;

	qsort(_nums, numsSize, sizeof(*_nums), cmp);

	for (i = 1; i < numsSize; i++) {
		if (nums[_nums[i]] != nums[_nums[i - 1]])
			continue;
		while (i < numsSize && nums[_nums[i]] == nums[_nums[i - 1]] &&
				abs(_nums[i] - _nums[i - 1] > k))
			i++;
		if (i >= numsSize)
			return false;
		if (nums[_nums[i]] == nums[_nums[i - 1]] &&
				abs(_nums[i] - _nums[i - 1] <= k))
			return true;
	}

	return false;
}

void tc_0(void)
{
	int nums[] = {1,2,8,9,10,11,12,13,14,1,3,4,5,6,7,1};
	int numsSize = sizeof(nums)/sizeof(*nums);
	printf("true\n%s\n",
		containsNearbyDuplicate(nums, numsSize, 6) ?
		"true" : "false");
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

