#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * Definition for an interval.
 */
struct Interval {
	int start;
	int end;
};

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findRightInterval(struct Interval* intervals, int intervalsSize, int* returnSize) {
	int *intv;
	int i, j, k, min;

	if (intervalsSize <= 0)
		return NULL;

	intv = malloc(sizeof(*intv) * intervalsSize);

	for (i = 0; i < intervalsSize; i++) {
		min = INT_MAX;
		intv[i] = -1;
		for (j = 0; j < intervalsSize; j++) {
			if (intervals[j].start < intervals[i].end)
				continue;
			k = intervals[j].start - intervals[i].end;
			if (k > min)
				continue;
			min = k;
			intv[i] = j;
			if (k == 0)
				break;
		}
	}

	*returnSize = intervalsSize;
	return intv;
}

void printArray(int *nums, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", nums[i]);
	printf("\n");
}

void test_case_0()
{
	struct Interval intervals[] = {
		{1,4},{2,3},{3,4}
	};
	int intervalsSize = sizeof(intervals)/sizeof(*intervals);
	int *nums, size;
	printf("  {1,4},{2,3},{3,4}\n");
	printf("  -1,2,-1\n");
	nums = findRightInterval(intervals, intervalsSize, &size);
	printArray(nums, size);
	free(nums);
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

