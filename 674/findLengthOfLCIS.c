#include <leetcode.h>

int findLengthOfLCIS(int* nums, int numsSize)
{
	int i, max, count;
	max = 1;
	count = 1;
	if (!numsSize)
		return 0;
	for (i = 1; i < numsSize; i++) {
		if (nums[i] > nums[i - 1]) {
			count++;
			continue;
		}
		if (count > max)
			max = count;
		count = 1;
	}
	if (count > max)
		return count;
	return max;
}

void tc_0(void)
{
	int nums[] = {1,3,5,7};
	int numsSize = sizeof(nums) / sizeof(*nums);
	printf("4\n%d\n\n", findLengthOfLCIS(nums, numsSize));
}

void tc_1(void)
{
	int nums[] = {1,3,5,4,7};
	int numsSize = sizeof(nums) / sizeof(*nums);
	printf("3\n%d\n\n", findLengthOfLCIS(nums, numsSize));
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	return 0;
}

