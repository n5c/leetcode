#include <leetcode.h>

void rotate(int *nums, int numsSize, int k)
{
	int i, j, tmp;
	k %= numsSize;
	if (!k)
		return;

	for (i = numsSize - k - 1, j = numsSize - 1; i >= 0; i--, j--) {
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}

	rotate(nums, k, k - (numsSize % k));
}

void tc_0(void)
{
	int nums[] = {1,2,3,4,5,6,7};
	int numsSize = sizeof(nums)/sizeof(*nums);
	rotate(nums, numsSize, 18);
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

