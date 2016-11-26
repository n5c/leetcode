#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
	int i, j;
	int bytechk[4][256] = {0};

	for (i = 0; i < numsSize; i++) {
		bytechk[0][nums[i] & 0xff]++;
		bytechk[1][(nums[i] >> 8) & 0xff]++;
		bytechk[2][(nums[i] >> 16) & 0xff]++;
		bytechk[3][(nums[i] >> 24) & 0xff]++;
	}

	for (i = 0, j = 0; i < 256; i++) {
		if (bytechk[0][i] % 3)
			j |= i;
		if (bytechk[1][i] % 3)
			j |= (i << 8);
		if (bytechk[2][i] % 3)
			j |= (i << 16);
		if (bytechk[3][i] % 3)
			j |= (i << 24);
	}

	return j;
}

void test_case_0()
{
	int nums[] = {
		1,2,3,4,5,4,3,4,3,2,2,1,1
	};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int num;

	num = singleNumber(nums, numsSize);
	printf("%d\n", num);
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

