#include <leetcode.h>

int searchInsert(int* nums, int numsSize, int target)
{
	int start, end, mid;
	mid = 0;
	start = 0;
	end = numsSize - 1;
	while (start <= end) {
		mid = ((start + end) >> 1);
		if (target == nums[mid])
			break;
		else if (target > nums[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}

	if (target > nums[mid]) {
		mid++;
	}

	return mid;
}

void tc_0(void)
{
	int nums[] = {1};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int target = 0;
	printf("%d\n", searchInsert(nums, numsSize, target));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

