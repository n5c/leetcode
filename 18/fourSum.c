#include <leetcode.h>

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize)
{
	int cmp(const void *a, const void *b) {
		const int *ia = a;
		const int *ib = b;
		return (*ia - *ib);
	}
	qsort(nums, numsSize, sizeof(*nums), cmp);

	int i, j, k, l;
	int **fourSums;

	fourSums = NULL;
	*returnSize = 0;
	l = 0;

	for (i = 0; i < numsSize; i++) {
		if (i)
			while (i < numsSize && nums[i] == nums[i - 1]) i++;
		for (j = numsSize - 1; j > i + 2; j--) {
			if (j < numsSize - 1)
				while (j > i && nums[j] == nums[j + 1]) j--;
			for (k = i + 1; k < j - 1; k++) {
				if (k != i + 1)
					while (k < j - 1 && nums[k] == nums[k - 1]) k++;

				int chk = target - (nums[i] + nums[j] + nums[k]);
				if (chk > nums[j]) {
					continue;
				} else if (chk < nums[i]) {
					while (j > i && nums[j] == nums[j - 1]) j--;
					continue;
				} if (chk < nums[k]) {
					continue;
				}

				if (k >= (j - 1))
					break;

				int mid, start = k + 1, end = j - 1, m = -1;
				while (start <= end) {
					mid = (start + end) >> 1;
					if (nums[mid] == chk) {
						m = mid;
						break;
					}
					else if (nums[mid] < chk)
						start = mid + 1;
					else if (nums[mid] > chk)
						end = mid - 1;
				}

				if (m == -1)
					continue;

				if (!*returnSize) {
					*returnSize = 16;
					fourSums = malloc(sizeof(*fourSums) * *returnSize);
				} else if (l >= *returnSize) {
					*returnSize += 16;
					fourSums = realloc(fourSums, sizeof(*fourSums) * *returnSize);
				}

				fourSums[l] = malloc(sizeof(**fourSums) * 4);
				fourSums[l][0] = nums[i];
				fourSums[l][1] = nums[k];
				fourSums[l][2] = nums[m];
				fourSums[l][3] = nums[j];
				l++;
			}
		}
	}

	*returnSize = l;
	return fourSums;
}

void print(int **sums, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d, %d, %d, %d\n",
			sums[i][0], sums[i][1], sums[i][2], sums[i][3]);
	printf("\n");
}

void tc_0(void)
{
	int nums[] = {1,0,-1,0,-2,2};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int target = 0;
	int size;
	int **sums = fourSum(nums, numsSize, target, &size);
	print(sums, size);
	for (int i = 0; i < size; i++)
		free(sums[i]);
	free(sums);
}

void tc_1(void)
{
	int nums[] = {-3,-2,-1,0,0,1,2,3};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int target = 0;
	int size;
	int **sums = fourSum(nums, numsSize, target, &size);
	print(sums, size);
	for (int i = 0; i < size; i++)
		free(sums[i]);
	free(sums);
}

void tc_2(void)
{
	int nums[] = {-4,-3,-2,-1,0,0,1,2,3,4};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int target = 0;
	int size;
	int **sums = fourSum(nums, numsSize, target, &size);
	print(sums, size);
	for (int i = 0; i < size; i++)
		free(sums[i]);
	free(sums);
}

void tc_3(void)
{
	int nums[] = {5,5,3,5,1,-5,1,-2};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int target = 4;
	int size;
	int **sums = fourSum(nums, numsSize, target, &size);
	print(sums, size);
	for (int i = 0; i < size; i++)
		free(sums[i]);
	free(sums);
}

void tc_4(void)
{
	int nums[] = {-5,-2,-4,-2,-5,-4,0,0};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int target = -13;
	int size;
	int **sums = fourSum(nums, numsSize, target, &size);
	print(sums, size);
	for (int i = 0; i < size; i++)
		free(sums[i]);
	free(sums);
}

void tc_5(void)
{
	int nums[] = {0,5,-8,-7,4,8,-4,3,9,7,8,10,3,-6,3,7,10,0};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int target = -12;
	int size;
	int **sums = fourSum(nums, numsSize, target, &size);
	print(sums, size);
	for (int i = 0; i < size; i++)
		free(sums[i]);
	free(sums);
}

int main(int argc, char *argv[])
{
	//tc_0();
	//tc_1();
	//tc_2();
	//tc_3();
	//tc_4();
	tc_5();
	return 0;
}

