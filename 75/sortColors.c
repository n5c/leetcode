#include <leetcode.h>

void sortColors(int* nums, int numsSize)
{
	int i, j;

	i = 0;
	j = 0;
	while (1) {
		while (j < numsSize && nums[j] == 0) j++;
		i = j + 1;
		while (i < numsSize && nums[i] != 0) i++;
		if (i < numsSize && j < numsSize) {
			int tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
		} else {
			break;
		}
	}

	while (1) {
		while (j < numsSize && nums[j] == 1) j++;
		i = j + 1;
		while (i < numsSize && nums[i] != 1) i++;
		if (i < numsSize && j < numsSize) {
			int tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
		} else {
			break;
		}
	}

	while (1) {
		while (j < numsSize && nums[j] == 2) j++;
		i = j + 1;
		while (i < numsSize && nums[i] != 2) i++;
		if (i < numsSize && j < numsSize) {
			int tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
		} else {
			break;
		}
	}
}

void tc_0(void)
{
	int nums[] = {0,1,2,2,1,2,1,0,0,2,0,0,1,1,1,0,2};
	int numsSize = sizeof(nums)/sizeof(*nums);
	printf("0,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2\n");
	sortColors(nums, numsSize);
	for (int i = 0; i < numsSize; i++) {
		if (i)
			printf(",");
		printf("%d", nums[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

