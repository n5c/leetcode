#include <leetcode.h>

int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int arrayPairSum(int* nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), cmp);

	int sum = 0;
	for (int i = 0; i < numsSize; i += 2)
		sum += nums[i];

	return sum;
}

void tc_0(void)
{
	int nums[] = {1,4,3,2};
	int numsSize = sizeof(nums)/sizeof(*nums);
	printf("%d\n", arrayPairSum(nums, numsSize));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

