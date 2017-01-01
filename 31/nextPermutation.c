#include <leetcode.h>

void nextPermutation(int* nums, int numsSize)
{
	int i, j, k, min;
	int cmp(const void *a, const void *b) {
		const int *ia = a;
		const int *ib = b;
		return *ia - *ib;
	}

	if (numsSize <= 1)
		return;

	for (i = numsSize - 2; (i >= 0) && (nums[i] >= nums[i + 1]); i--);

	if (i >= 0) {
		for (k = i + 1, min = nums[k], j = i + 2; j < numsSize; j++) {
			if (nums[j] <= nums[i])
				continue;
			if (nums[j] >= min)
				continue;
			min = nums[j];
			k = j;
		}

		j = nums[i];
		nums[i] = nums[k];
		nums[k] = j;
	}

	qsort(&nums[i + 1], (numsSize - i - 1), sizeof(*nums), cmp);
}

void print(int *nums, int numsSize)
{
	if (!numsSize)
		return;
	printf("%d", nums[0]);
	for (int i = 1; i < numsSize; i++)
		printf(",%d", nums[i]);
	printf("\n\n");
}

void tc_0(void)
{
	int nums[] = {1,1,1,3,1};
	int numsSize = sizeof(nums)/sizeof(*nums);
	nextPermutation(nums, numsSize);
	print(nums, numsSize);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

