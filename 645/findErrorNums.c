#include <leetcode.h>

int* findErrorNums(int* nums, int numsSize, int* returnSize)
{
	int i, chks[numsSize], *errs;
	*returnSize = 2;
	errs = malloc(sizeof(*errs) * 2);
	for (i = 0; i < numsSize; i++)
		chks[i] = 0;
	for (i = 0; i < numsSize; i++) {
		if (chks[nums[i] - 1])
			errs[0] = nums[i];
		chks[nums[i] - 1] = 1;

	}
	for (i = 0; i < numsSize; i++) {
		if (!chks[i])
			break;

	}
	errs[1] = i + 1;
	return errs;

}

void tc_0(void)
{
	int nums[] = {1,2,2,4};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int *errs;
	int returnSize;
	errs = findErrorNums(nums, numsSize, &returnSize);
	printf("2,3\n%d,%d\n\n", errs[0], errs[1]);
	free(errs);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

