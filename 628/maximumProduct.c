#include <leetcode.h>

static int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int maximumProduct(int* nums, int numsSize)
{
	int i, mul, max = INT_MIN;
	qsort(nums, numsSize, sizeof(*nums), cmp);
	mul = (nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3]);
	if (mul > max)
		max = mul;
	mul = (nums[numsSize - 1] * nums[0] * nums[1]);
	if (mul > max)
		max = mul;
	return max;
}

void tc_0(void)
{
	int nums[] = {1,2,3};
	int numsSize = sizeof(nums)/sizeof(*nums);
	printf("6\n%d\n", maximumProduct(nums, numsSize));
}

void tc_1(void)
{
	int nums[] = {1,2,3,4};
	int numsSize = sizeof(nums)/sizeof(*nums);
	printf("24\n%d\n", maximumProduct(nums, numsSize));
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	return 0;
}

