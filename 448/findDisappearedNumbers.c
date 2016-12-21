#include <leetcode.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
	int *returnNums, i, j, k;

	*returnSize = 0;
	for (i = 0; i < numsSize; i++) {
		j = nums[i] - 1;
		if (j < 0 || j == i)
			continue;

		nums[i] = 0;
		while (j >= 0 && j != (k = nums[j] - 1)) {
			nums[j] = j + 1;
			j = k;
		}

		if ((j >= 0) && (j == k))
			(*returnSize)++;
	}

	returnNums = malloc(sizeof(*returnNums) * *returnSize);

	for (i = 0, j = 0; j < *returnSize; i++) {
		if (nums[i])
			continue;
		returnNums[j++] = i + 1;
	}

	return returnNums;
}

void print(int *nums, int size)
{
	for (int i = 0; i < size; i++) {
		printf("%d", nums[i]);
		if (i + 1 < size)
			printf(",");
	}
	printf("\n\n");
}

void tc_0(void)
{
	int nums[] = {4,3,2,7,8,2,3,1};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int *returnNums, returnSize;

	returnNums = findDisappearedNumbers(nums, numsSize, &returnSize);
	print(returnNums, returnSize);
	free(returnNums);
}

void tc_1(void)
{
	int nums[] = {1,1};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int *returnNums, returnSize;

	returnNums = findDisappearedNumbers(nums, numsSize, &returnSize);
	print(returnNums, returnSize);
	free(returnNums);
}

void tc_2(void)
{
	int nums[] = {3,1,1,3};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int *returnNums, returnSize;

	returnNums = findDisappearedNumbers(nums, numsSize, &returnSize);
	print(returnNums, returnSize);
	free(returnNums);
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	tc_2();
	return 0;
}

