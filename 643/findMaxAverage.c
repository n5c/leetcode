#include <leetcode.h>

double findMaxAverage(int* nums, int numsSize, int k)
{
	int i, j, sum, max;
	for (i = 0, sum = 0; i < k; i++)
		sum += nums[i];
	max = sum;

	for (j = 0; i < numsSize; i++, j++) {
		sum = sum + nums[i] - nums[j];
		if (sum > max)
			max = sum;

	}

	return ((double)max / (double)k);

}

void tc_0(void)
{
	int nums[] = {1,12,-5,-6,50,3};
	int numsSize = sizeof(nums)/sizeof(*nums);
	printf("12.75\n%f\n\n", findMaxAverage(nums, numsSize, 4));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

