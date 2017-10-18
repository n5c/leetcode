#include <leetcode.h>

static int __target;

static bool helper(int *nums, int numsSize, int k, int start, int target, bool *skips, bool partial)
{
	if (!k)
		return true;

	bool __skips[numsSize];

	for (int i = start; i < numsSize; ++i) {
		if (skips[i])
			continue;
		memcpy(__skips, skips, sizeof(__skips));
		int target2 = target - nums[i];
		if (target2 < 0) {
			if (partial)
				continue;
			break;
		}
		__skips[i] = true;
		if (target2 == 0)
			return helper(nums, numsSize, k - 1, 0, __target, __skips, false);
		if (helper(nums, numsSize, k, i + 1, target2, __skips, true))
			return true;
		if (partial)
			continue;
		break;
	}

	return false;
}

static int cmp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

bool canPartitionKSubsets(int* nums, int numsSize, int k)
{
	int i;
	bool skips[16] = {0};
	for (i = 0, __target = 0; i < numsSize; ++i)
		__target += nums[i];
	if (__target % k)
		return false;
	__target /= k;
	qsort(nums, numsSize, sizeof(*nums), cmp);
	return helper(nums, numsSize, k, 0, __target, skips, false);
}

void tc_0(void)
{
	int nums[] = {4,3,2,3,5,2,1};
	int numsSize = sizeof(nums) / sizeof(*nums);
	const char *boolstr[] = {"false","true"};
	printf("true\n%s\n\n", boolstr[canPartitionKSubsets(nums, numsSize, 4)]);
}

void tc_1(void)
{
	int nums[] = {1,2,3,4,5,6,3,8};
	int numsSize = sizeof(nums) / sizeof(*nums);
	const char *boolstr[] = {"false","true"};
	printf("true\n%s\n\n", boolstr[canPartitionKSubsets(nums, numsSize, 4)]);
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	return 0;
}

