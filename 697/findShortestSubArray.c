#include <leetcode.h>

static uint16_t chk[50000][3];
int findShortestSubArray(int* nums, int numsSize)
{
	int i = 0, min, max = 0, maxi;
	memset(chk, 0, sizeof(chk));
	chk[nums[i]][0] = 1;
	max = 1;
	maxi = 0;
	min = 1;
	for (i = 1; i < numsSize; ++i) {
		if (!chk[nums[i]][0]) {
			chk[nums[i]][0] = 1;
			chk[nums[i]][1] = i;
		} else {
			++chk[nums[i]][0];
			chk[nums[i]][2] = i;
			int tmp = chk[nums[i]][2] - chk[nums[i]][1] + 1;
			if (chk[nums[i]][0] > max) {
				max = chk[nums[i]][0];
				maxi = nums[i];
				min = tmp;
			} else if ((chk[nums[i]][0] == max) && (tmp < min)) {
				maxi = nums[i];
				min = tmp;
			}
		}
	}
	return min;
}

void tc_0(void)
{
	int nums[] = {1,2,2,3,1};
	int numsSize = sizeof(nums) / sizeof(*nums);
	printf("2\n%d\n\n", findShortestSubArray(nums, numsSize));
}

void tc_1(void)
{
	int nums[] = {1,2,2,3,1,4,2};
	int numsSize = sizeof(nums) / sizeof(*nums);
	printf("6\n%d\n\n", findShortestSubArray(nums, numsSize));
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	return 0;
}

