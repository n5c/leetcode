#include <leetcode.h>

char** findRelativeRanks(int* nums, int numsSize, int* returnSize)
{
	int i, j, k;
	char *rankname[3] = {
		"Gold Medal", "Silver Medal", "Bronze Medal"
	};
	char **ranks, str[20];

	*returnSize = numsSize;
	ranks = malloc(sizeof(*ranks) * numsSize);

	for (i = 0; i < numsSize; i++)
		ranks[i] = (char *)i;

	for (i = 1; i < numsSize; i++) {
		j = i;
		while (j) {
			k = (((j + 1) >> 1) - 1);
			if (nums[k] <= nums[j])
				break;

			char *ptmp = ranks[k];
			ranks[k] = ranks[j];
			ranks[j] = ptmp;

			int tmp = nums[k];
			nums[k] = nums[j];
			nums[j] = tmp;

			j = k;
		}
	}

	for (i = numsSize - 1; i > 0; i--) {
		char *ptmp = ranks[0];
		ranks[0] = ranks[i];
		ranks[i] = ptmp;

		int tmp = nums[0];
		nums[0] = nums[i];
		nums[i] = tmp;

		j = 0;
		while (j < i) {
			k = (((j + 1) << 1) - 1);
			if (k >= i)
				break;
			if (((k + 1) < i) && (nums[k + 1] < nums[k]))
				k++;
			if (nums[k] >= nums[j])
				break;

			ptmp = ranks[k];
			ranks[k] = ranks[j];
			ranks[j] = ptmp;

			tmp = nums[k];
			nums[k] = nums[j];
			nums[j] = tmp;

			j = k;
		}
	}

	i = 0;
	while (i < numsSize) {
		j = i;
		k = (int)ranks[j];
		while (j >= 0 && j < numsSize && k >= 0 && k < numsSize) {
			if (j <= 2)
				snprintf(str, 20, "%s", rankname[j]);
			else
				snprintf(str, 20, "%d", j + 1);
			j = k;
			k = (int)ranks[j];
			ranks[j] = strdup(str);
		}
		i++;
	}

	return ranks;
}

void tc_0(void)
{
	int nums[] = {5,4,3,2,1};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int returnSize;
	char **s = findRelativeRanks(nums, numsSize, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		if (i)
			printf(", ");
		printf("%s", s[i]);
		free(s[i]);
	}
	printf("\n");
	free(s);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

