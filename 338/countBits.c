#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize)
{
	int i, j, k, *nums/*, *dst, *src*/;
	// int bitcnt[] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};

	nums = malloc(sizeof(*nums) * (num + 1));
	/* for (i = 0; i <= num; i++) {
		nums[i] = bitcnt[i & 0xf] + bitcnt[(i >> 4) & 0xf] +
			bitcnt[(i >> 8) & 0xf] + bitcnt[(i >> 12) & 0xf] +
			bitcnt[(i >> 16) & 0xf] + bitcnt[(i >> 20) & 0xf] +
			bitcnt[(i >> 24) & 0xf] + bitcnt[(i >> 28) & 0xf];
	} */

	nums[0] = 0;
	nums[1] = 1;
	i = 2;
	/* while (i <= num) {
		dst = &nums[i];
		src = &nums[0];
		k = (((num - i) < i) ? num - i : i);
		for (j = 0; j <= k; j++) {
			dst[j] = 1 + src[j];
		}

		i <<= 1;
	} */
	while (1) {
		for (j = i, k = 0; (k < i) && (j <= num); j++, k++)
			nums[j] = 1 + nums[k];
		if (j > num)
			break;
		i <<= 1;
	}

	*returnSize = (num + 1);

	return nums;
}

void printArray(int *nums, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		printf("%d", nums[i]);
		if ((i + 1) < size)
			printf(",");
	}
	printf("\n");
}

void test_case_0()
{
	int i, *nums, size;
	/* for (i = 0; i < 100000; i++) {
		nums = countBits(i, &size);
		free(nums);
	} */

	nums = countBits(100, &size);
	printArray(nums, size);
	free(nums);
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

