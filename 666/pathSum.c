#include <leetcode.h>

int pathSum(int* nums, int numsSize)
{
	int i, j, *arr1[1 << 5] = {0}, arr2[1 << 5];
	int pos, sum, _sum, D, P, V;

	arr1[0] = &arr2[0];
	*arr1[0] = nums[0] % 10;
	for (i = 1, j = 1; i < numsSize; i++, j++) {
		D = nums[i] / 100;
		P = (nums[i] / 10) % 10;
		V = nums[i] % 10;
		pos = (1 << (D - 1)) + P - 2;
		arr1[pos] = &arr2[j];
		*arr1[pos] = V;
	}

	i = 1;
	_sum = 0;
	sum = 0;
	while (1) {
		_sum += *arr1[i - 1];
		if (arr1[(i << 1) - 1]) {
			i <<= 1;
		} else if (arr1[i << 1]) {
			i <<= 1;
			i += 1;
		} else {
			sum += _sum;
			while (i) {
				_sum -= *arr1[i - 1];
				j = (i & ~(0x1)) + 1;
				if (i != j && arr1[j - 1]) {
					i = j;
					break;
				}
				i >>= 1;
			}
			if (!i)
				break;
		}
	}
	return sum;
}

void tc_0(void)
{
	int nums[] = {113,215,221};
	int numsSize = sizeof(nums) / sizeof(*nums);
	printf("12\n%d\n\n", pathSum(nums, numsSize));
}

void tc_1(void)
{
	int nums[] = {113,215,221,316,327,338,349};
	int numsSize = sizeof(nums) / sizeof(*nums);
	printf("54\n%d\n\n", pathSum(nums, numsSize));
}

void tc_2(void)
{
	int nums[] = {113,215,221,311,322,333,344,411,422,443,464};
	int numsSize = sizeof(nums) / sizeof(*nums);
	printf("53\n%d\n\n", pathSum(nums, numsSize));
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	tc_2();
	return 0;
}

