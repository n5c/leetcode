#include <leetcode.h>

int *seq;
int *seqn;
int seqSize;
int findNumberOfLIS(int* nums, int numsSize)
{
	int i, j, __seq, max, maxn;

	if (!numsSize)
		return 0;

	if (seqSize < numsSize) {
		seqSize = numsSize;
		seq = realloc(NULL, sizeof(*seq) * (seqSize << 1));
		seqn = &seq[seqSize];
	}

	for (i = 0; i < numsSize; i++) {
		seq[i] = 1;
		seqn[i] = 1;
	}
	max = 1;
	for (i = 0; i < numsSize - 1; i++) {
		__seq = seq[i] + 1;
		for (j = i + 1; j < numsSize; j++) {
			if (nums[j] <= nums[i])
				continue;
			if (seq[j] > __seq)
				continue;
			if (seq[j] == __seq) {
				seqn[j] += seqn[i];
			} else {
				seq[j] = __seq;
				seqn[j] = seqn[i];
			}
		}
	}

	max = seq[0];
	maxn = 1;
	for (i = 1; i < numsSize; i++) {
		if (seq[i] < max) {
			continue;
		} else if (seq[i] > max) {
			max = seq[i];
			maxn = seqn[i];
		} else {
			maxn += seqn[i];
		}
	}

	return maxn;
}

void tc_0(void)
{
	int nums[] = {1,3,5,4,7};
	int numsSize = sizeof(nums) / sizeof(*nums);
	printf("2\n%d\n\n", findNumberOfLIS(nums, numsSize));
}

void tc_1(void)
{
	int nums[] = {10,11,12,7,8,9,3,4,5,14};
	int numsSize = sizeof(nums) / sizeof(*nums);
	printf("3\n%d\n\n", findNumberOfLIS(nums, numsSize));
}

void tc_2(void)
{
	int nums[] = {1,1,1,1,2,2,2,2,3,3,3};
	int numsSize = sizeof(nums) / sizeof(*nums);
	printf("48\n%d\n\n", findNumberOfLIS(nums, numsSize));
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	tc_2();
	return 0;
}

