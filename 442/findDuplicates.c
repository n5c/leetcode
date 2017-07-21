#include <leetcode.h>

int* findDuplicates(int* nums, int numsSize, int* returnSize)
{
	int i, j, k;
	int *dups;
	dups = malloc(sizeof(*dups) * (numsSize / 2));
	for (i = 0, k = 0; i < numsSize; i++) {
		while (nums[i] > 0) {
			j = nums[i] - 1;
			if (nums[j] <= 0) {
				if (!nums[j]) {
					nums[j] = -1;
					dups[k++] = j + 1;
				}
				break;
			}
			nums[i] = nums[j];
			nums[j] = 0;
		}
	}
	*returnSize = k;
	return dups;
}

void tc_0(void)
{
	int nums[] = {14,4,3,2,7,8,2,3,1,9,10,12,13,14,15};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int returnSize;
	int *dups;
	dups = findDuplicates(nums, numsSize, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		if (i)
			printf(", ");
		printf("%d", dups[i]);
	}
	printf("\n\n");
	free(dups);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

