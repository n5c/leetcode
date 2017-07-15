#include <leetcode.h>

int findUnsortedSubarray(int* nums, int numsSize)
{
	int i, j, k, min, max;
	min = max = 0;

	for (i = 1; i < numsSize; i++) {
		if (nums[i] < nums[i - 1])
			break;
	}

	if (i >= numsSize)
		return 0;

	min = j = i;
	max = i - 1;

	for (i = numsSize - 2; i > j; i--) {
		if (nums[i] > nums[i + 1])
			break;
	}

	k = i;

	if (nums[i + 1] < nums[min])
		min = i + 1;
	if (nums[i] > nums[max])
		max = i;

	for (i = j; i < k; i++) {
		if (nums[i] < nums[min])
			min = i;
		if (nums[i] > nums[max])
			max = i;
	}

	for (i = 0; i < j; i++) {
		if (nums[i] > nums[min])
			break;
	}
	j = i;

	for (i = numsSize - 1; i >= k; i--) {
		if (nums[i] < nums[max])
			break;
	}
	k = i;

	return (k - j + 1);
}

void tc_0(void)
{
	int nums[] = {2, 6, 4, 8, 10, 9, 15};
	int numsSize = sizeof(nums)/sizeof(*nums);
	printf("5\n%d\n\n", findUnsortedSubarray(nums, numsSize));
}

void tc_1(void)
{
	int nums[] = {2, 6, 4, 1, 10, 9, 15};
	int numsSize = sizeof(nums)/sizeof(*nums);
	printf("6\n%d\n\n", findUnsortedSubarray(nums, numsSize));
}

void tc_2(void)
{
	int nums[] = {2, 6, 4, 20, 12, 10, 9, 15};
	int numsSize = sizeof(nums)/sizeof(*nums);
	printf("7\n%d\n\n", findUnsortedSubarray(nums, numsSize));
}

void tc_3(void)
{
	int nums[] = {2, 3, 4, 8, 10, 13, 15};
	int numsSize = sizeof(nums)/sizeof(*nums);
	printf("0\n%d\n\n", findUnsortedSubarray(nums, numsSize));
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	tc_2();
	tc_3();
	return 0;
}

