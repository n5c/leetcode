#include <leetcode.h>

/**
 *  * Return an array of arrays of size *returnSize.
 *   * Note: The returned array must be malloced, assume caller calls free().
 *    */
int** threeSum(int* nums, int numsSize, int* returnSize)
{
	int cmp(const void *a, const void *b) {
		const int *ia = a;
		const int *ib = b;
		return (*ia - *ib);
	}
	qsort(nums, numsSize, sizeof(*nums), cmp);

	int i, j, k, **sums, target;

	sums = NULL;
	*returnSize = 0;

	for (i = 0; i < numsSize; i++) {
		j = numsSize - 1;
		while (i < j && nums[i] == nums[i + 1]) i++;

		if (!nums[i]) {
			if (i >= 2 && nums[i] == nums[i - 1] &&
			    nums[i] == nums[i - 2]) {
				if (!*returnSize) {
					*returnSize = 1;
					sums = malloc(sizeof(*sums) * (*returnSize));
				} else {
					(*returnSize)++;
					sums = realloc(sums, sizeof(*sums) * (*returnSize));
				}

				sums[*returnSize - 1] = malloc(sizeof(**sums) * 3);
				sums[*returnSize - 1][0] = nums[i];
				sums[*returnSize - 1][1] = nums[i];
				sums[*returnSize - 1][2] = nums[i];
			}
		}

		for (; j > i; j--) {
			while (j > i && nums[j] == nums[j - 1]) j--;
			k = -1;
			target = 0 - (nums[i] + nums[j]);
			if (target >= nums[j]) {
				if ((target > nums[j]) ||
				    (j == numsSize - 1) ||
				    (target != nums[j + 1]))
					break;
				k = j;
			} else if (target <= nums[i]) {
				if ((target < nums[i]) || (!i) ||
				    (target != nums[i - 1])) {
					numsSize = j;
					continue;
				}
				k = i;
			} else {
				int mid, start = i + 1, end = j - 1;
				while (start <= end) {
					mid = (start + end) >> 1;
					if (nums[mid] == target) {
						k = mid;
						break;
					} else if (nums[mid] > target) {
						end = mid - 1;
					} else {
						start = mid + 1;
					}
				}
			}

			if (k == -1)
				continue;

			if (!*returnSize) {
				*returnSize = 1;
				sums = malloc(sizeof(*sums) * (*returnSize));
			} else {
				(*returnSize)++;
				sums = realloc(sums, sizeof(*sums) * (*returnSize));
			}

			sums[*returnSize - 1] = malloc(sizeof(**sums) * 3);
			sums[*returnSize - 1][0] = nums[i];
			sums[*returnSize - 1][1] = nums[k];
			sums[*returnSize - 1][2] = nums[j];
		}
	}

	return sums;
}

void printThreeSums(int **sums, int sumsSize)
{
	int i;
	for (i = 0; i < sumsSize; i++)
		printf("%d, %d, %d\n", sums[i][0], sums[i][1], sums[i][2]);
	printf("\n");
}

void tc_0(void)
{
	int nums[] = {2,-1,-1,-1,-1};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int i, **sums, size;
	sums = threeSum(nums, numsSize, &size);
	printThreeSums(sums, size);
	for (i = 0; i < size; i++)
		free(sums[i]);
	free(sums);
}

void tc_1(void)
{
	int nums[] = {-1, 0, 1, 2, -1, -4};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int i, **sums, size;
	sums = threeSum(nums, numsSize, &size);
	printThreeSums(sums, size);
	for (i = 0; i < size; i++)
		free(sums[i]);
	free(sums);
}

void tc_2(void)
{
	int nums[] = {-1, -2, -2, -3, 5, 0, 1, 4, -1, -4};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int i, **sums, size;
	sums = threeSum(nums, numsSize, &size);
	printThreeSums(sums, size);
	for (i = 0; i < size; i++)
		free(sums[i]);
	free(sums);
}

void tc_3(void)
{
	int nums[] = {0,0,0,0,0,0};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int i, **sums, size;
	sums = threeSum(nums, numsSize, &size);
	printThreeSums(sums, size);
	for (i = 0; i < size; i++)
		free(sums[i]);
	free(sums);
}

void tc_4(void)
{
	int nums[] = {0,0,-1, -2, -3, -7, 0,0,1, 2, 4, 5, 0,0};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int i, **sums, size;
	sums = threeSum(nums, numsSize, &size);
	printThreeSums(sums, size);
	for (i = 0; i < size; i++)
		free(sums[i]);
	free(sums);
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	tc_2();
	tc_3();
	tc_4();
	return 0;
}

