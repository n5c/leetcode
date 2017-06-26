#include <leetcode.h>

int maxSubArray(int* nums, int numsSize)
{
	int i, sum, max;
	i = 0;
	sum = 0;
	max = INT_MIN;
	while (i < numsSize) {
		sum += nums[i++];
		if (sum > max)
			max = sum;
		if (sum <= 0)
			sum = 0;
	}
	return max;
}

void tc_0(void)
{
	int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
	int numsSize = sizeof(nums)/sizeof(*nums);
	printf("%d\n", maxSubArray(nums, numsSize));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

