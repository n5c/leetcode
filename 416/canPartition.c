#include <leetcode.h>

static bool helper(int *nums, int numsSize, int target)
{
	if (!numsSize)
		return false;
	for (int i = 0; i < numsSize; ++i) {
		int __target = target - nums[i];
		if (__target == 0)
			return true;
		if (__target < 0)
			break;
		bool result = helper(&nums[i + 1], numsSize - i - 1, __target);
		if (result)
			return true;
	}
	return false;

}

static int cmp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

bool canPartition(int* nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(*nums), cmp);
	int i, j, target;
	for (i = 0, target = 0; i < numsSize; ++i)
		target += nums[i];
	if (target & 1)
		return false;
	target >>= 1;
	return helper(nums, numsSize, target);
}

void tc_0(void)
{
	int nums[] = {1,5,11,5};
	int numsSize = sizeof(nums) / sizeof(*nums);
	const char *boolstr[] = {"false", "true"};
	printf("true\n%s\n\n", boolstr[canPartition(nums, numsSize)]);
}

void tc_1(void)
{
	int nums[] = {1,2,3,5};
	int numsSize = sizeof(nums) / sizeof(*nums);
	const char *boolstr[] = {"false", "true"};
	printf("false\n%s\n\n", boolstr[canPartition(nums, numsSize)]);
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	return 0;
}

