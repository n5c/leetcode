#include <stdio.h>

int minMoves(int* nums, int numsSize)
{
#if 0
	int i, max, maxidx, count;
	int equal;

	count = 0;
	maxidx = 0;
	while (1) {
		equal = 1;
		max = nums[maxidx];
		for (i = 0; i < numsSize; i++) {
			if (nums[i] == max)
				continue;
			equal = 0;
			if (nums[i] < max)
				continue;
			max = nums[i];
			maxidx = i;
		}

		if (equal)
			break;

		for (i = 0; i < maxidx; i++)
			nums[i]++;

		for (i = (maxidx + 1); i < numsSize; i++)
			nums[i]++;

		count++;
	}

	return count;
#endif

	int i, j, k, l, count;

	/* heapify */
	for (i = 1; i < numsSize; i++) {
		j = i;
		while (j) {
			k = ((j + 1) >> 1) - 1;
			if (nums[k] >= nums[j])
				break;
			l = nums[j];
			nums[j] = nums[k];
			nums[k] = l;
			j = k;
		}
	}

	for (i = numsSize - 1, count = 0; i; i--) {
		l = nums[i];
		nums[i] = nums[0];
		nums[0] = l;

		j = 0;
		while (j < i) {
			k = ((j + 1) << 1) - 1;
			if (k >= i)
				break;
			if (((k + 1) < i) && (nums[k + 1] > nums[k]))
				k++;
			if (nums[k] <= nums[j])
				break;
			l = nums[j];
			nums[j] = nums[k];
			nums[k] = l;
			j = k;
		}

		count += ((nums[i] - nums[0]) * (numsSize - i));
	}

	return count;
}

void test_case_0()
{
	int nums[] = {1,2,3,4,5,6,20,31};
	int numsSize = sizeof(nums)/sizeof(*nums);
	printf("   1,2,3,4,5,6,20,31\n");
	printf("   64\n");
	printf("=> %d\n", minMoves(nums, numsSize));
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

