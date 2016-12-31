#include <leetcode.h>

int minMoves2(int* nums, int numsSize)
{
	int i, j, k, count, diff;
	int cmp(const void *a, const void *b) {
		const int *ia = a;
		const int *ib = b;
		return *ia - *ib;
	}

	if (numsSize == 1)
		return 0;
	if (numsSize == 2)
		return abs(nums[0] - nums[1]);

	qsort(nums, numsSize, sizeof(*nums), cmp);

	i = 1;
	j = numsSize - 2;
	k = 0;
	count = 0;
	while (i <= j) {
		if (k & 1) {
			diff = abs(nums[i] - nums[i - 1]);
			count += diff * i;
			i++;
		} else {
			diff = abs(nums[j] - nums[j + 1]);
			count += diff * (numsSize - j - 1);
			j--;
		}
		k++;
	}

	diff = abs(nums[i] - nums[i - 1]);
	count += diff * ((i < (numsSize - j - 1)) ? i : (numsSize - j - 1));

	return count;
}

void tc_0(void)
{
	int nums[] = {1,2,3};
	int numsSize = sizeof(nums)/sizeof(*nums);
	printf("2\n");
	printf("%d\n\n", minMoves2(nums, numsSize));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

