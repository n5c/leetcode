#include <leetcode.h>

static int cmp (const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int findLHS(int* nums, int numsSize)
{
	int i, diff, count[2], currcnt, max;

	if (!numsSize || numsSize == 1)
		return 0;

	qsort(nums, numsSize, sizeof(*nums), cmp);
	max = 0;
	currcnt = 0;
	count[0] = 1;
	count[1] = 0;
	for (i = 1; i < numsSize; i++) {
		diff = nums[i] - nums[i - 1];
		if (!diff) {
			count[currcnt]++;
		} else {
			if ((count[0] && count[1]) && (count[0] + count[1] > max))
				max = count[0] + count[1];
			if (diff == 1) {
				currcnt = ((currcnt + 1) % 2);
			} else {
				count[0] = 0;
				count[1] = 0;
			}
			count[currcnt] = 1;
		}
	}

	if ((count[0] && count[1]) && (count[0] + count[1] > max))
		max = count[0] + count[1];

	return max;
}

void tc_0(void)
{
	int nums[] = {1,3,2,2,5,2,3,7};
	int numsSize = sizeof(nums)/sizeof(*nums);
	printf("5\n%d\n\n", findLHS(nums, numsSize));
}

void tc_1(void)
{
	int nums[] = {1,2,2,1};
	int numsSize = sizeof(nums)/sizeof(*nums);
	printf("4\n%d\n\n", findLHS(nums, numsSize));
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	return 0;
}

