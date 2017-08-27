#include <leetcode.h>

bool checkPossibility(int* nums, int numsSize)
{
	int i, j;
	if (numsSize <= 2)
		return true;
	j = -1;
	if (nums[numsSize - 1] < nums[numsSize - 2]) {
		nums[numsSize - 1] = nums[numsSize - 2];
		j++;
	}
	for (i = numsSize - 2; i; i--) {
		if (nums[i] < nums[i - 1]) {
			if (nums[i + 1] > nums[i - 1])
				nums[i] = nums[i + 1];
			else
				nums[i - 1] = nums[i];
			j++;
			if (j)
				return false;
		}
	}
	return true;
}

void tc_0(void)
{
	int nums[] = {4,2,3};
	int numsSize = sizeof(nums) / sizeof(*nums);
	printf("true\n%s\n\n", checkPossibility(nums, numsSize) ?
			"true" : "false");
}

void tc_1(void)
{
	int nums[] = {4,2,1};
	int numsSize = sizeof(nums) / sizeof(*nums);
	printf("false\n%s\n\n", checkPossibility(nums, numsSize) ?
			"true" : "false");
}

void tc_2(void)
{
	int nums[] = {3,4,2,3};
	int numsSize = sizeof(nums) / sizeof(*nums);
	printf("false\n%s\n\n", checkPossibility(nums, numsSize) ?
			"true" : "false");
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	tc_2();
	return 0;
}

