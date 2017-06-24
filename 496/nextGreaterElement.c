#include <leetcode.h>

int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize)
{
	int i, j, *elements, *ngidx;

	if (!findNumsSize || !numsSize) {
		*returnSize = 0;
		return NULL;
	}

	*returnSize = findNumsSize;
	elements = malloc(sizeof(*elements) * *returnSize);
	ngidx = malloc(sizeof(*ngidx) * numsSize);

	ngidx[numsSize - 1] = -1;
	for (i = numsSize - 2; i >= 0; i--) {
		j = i + 1;
		while (j >= 0 && j < numsSize && nums[j] <= nums[i])
			j = ngidx[j];
		ngidx[i] = j;
	}

	for (i = 0; i < findNumsSize; i++) {
		for (j = 0; j < numsSize && findNums[i] != nums[j]; j++);
		elements[i] = ngidx[j] == -1 ? -1 : nums[ngidx[j]];
	}

	return elements;
}

void tc_0(void)
{
	int findNums[] = {4,1,2};
	int findNumsSize = sizeof(findNums)/sizeof(*findNums);
	int nums[] = {1,3,4,2};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int returnSize;
	int *elements = nextGreaterElement(findNums, findNumsSize,
				nums, numsSize, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		if (i)
			printf(", ");
		printf("%d", elements[i]);
	}
	printf("\n");
	free(elements);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

