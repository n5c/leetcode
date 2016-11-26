#include <leetcode.h>

int* twoSum(int* nums, int numsSize, int target)
{
	int *twosum;
	int i, j, k, l;

	twosum = malloc(sizeof(*twosum) * numsSize);

	for (i = 0; i < numsSize; i++)
		twosum[i] = i;

	for (i = 1; i < numsSize; i++) {
		j = i;
		while (j) {
			k = ((j + 1) >> 1) - 1;
			if (nums[twosum[k]] >= nums[twosum[j]])
				break;
			l = twosum[j];
			twosum[j] = twosum[k];
			twosum[k] = l;
			j = k;
		}
	}

	for (i = (numsSize - 1); i > 0; i--) {
		l = twosum[i];
		twosum[i] = twosum[0];
		twosum[0] = l;

		j = 0;
		while (1) {
			k = ((j + 1) << 1) - 1;
			if (k >= i)
				break;
			if ((k + 1 < i) && (nums[twosum[k + 1]] > nums[twosum[k]]))
				k++;
			if (nums[twosum[k]] <= nums[twosum[j]])
				break;
			l = twosum[j];
			twosum[j] = twosum[k];
			twosum[k] = l;
			j = k;
		}
	}

	for (i = 0, j = numsSize - 1; i < j;) {
		if (nums[twosum[i]] + nums[twosum[j]] == target)
			break;
		else if (nums[twosum[i]] + nums[twosum[j]] < target)
			i++;
		else /* i + j > target */
			j--;
	}

	twosum[0] = twosum[i];
	twosum[1] = twosum[j];

	return twosum;
}

void tc_0(void)
{
	int nums[] = {100, 22, 55, 77, 1234, 90, 270, 99};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int *new;
	new = twoSum(nums, numsSize, 370);
	printf("100, 270: %d, %d\n", new[0], new[1]);
	free(new);
}

void tc_1(void)
{
	int nums[] = {100, 22, 55, 77, 1234, 90, 270, 99};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int *new;
	new = twoSum(nums, numsSize, 189);
	printf("90, 99: %d, %d\n", new[0], new[1]);
	free(new);
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	return 0;
}

