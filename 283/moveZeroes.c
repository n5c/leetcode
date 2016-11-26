#include <stdio.h>

void moveZeroes(int* nums, int numsSize)
{
	int i, j;

	/* find the first 0 */
	for (i = 0; (i < numsSize) && nums[i]; i++);
	j = i;

	for (; i < numsSize; i++) {
		if (!nums[i])
			continue;
		nums[j] = nums[i];
		j++;
	}

	for (; j < numsSize; j++) {
		if (!nums[j])
			continue;
		nums[j] = 0;
	}
}

void print(int *nums, int numsSize)
{
	int i;
	if (!numsSize)
		return;
	printf("%d", nums[0]);
	for (i = 1; i < numsSize; i++)
		printf(",%d",nums[i]);
	printf("\n");
}

void test_case_0(void)
{
	int nums[] = {0, 1, 0, 3, 12};
	printf("\n1,3,12,0,0:\n");
	moveZeroes(nums, sizeof(nums)/sizeof(int));
	print(nums,sizeof(nums)/sizeof(int));
}

void test_case_1(void)
{
	int nums[] = {0, 0, 0, 0, 0};
	printf("\n0,0,0,0,0:\n");
	moveZeroes(nums, sizeof(nums)/sizeof(int));
	print(nums,sizeof(nums)/sizeof(int));
}

void test_case_2(void)
{
	int nums[] = {3, 1, 4, 3, 12};
	printf("\n3,1,4,3,12:\n");
	moveZeroes(nums, sizeof(nums)/sizeof(int));
	print(nums,sizeof(nums)/sizeof(int));
}

void test_case_3(void)
{
	int nums[] = {};
	printf("\n:\n");
	moveZeroes(nums, sizeof(nums)/sizeof(int));
	print(nums,sizeof(nums)/sizeof(int));
}

void test_case_4(void)
{
	int nums[] = {1,2,3,0,0,0,4,5,6,0,0,0,7,8,9};
	printf("\n1,2,3,4,5,6,7,8,9,0,0,0,0,0,0:\n");
	moveZeroes(nums, sizeof(nums)/sizeof(int));
	print(nums,sizeof(nums)/sizeof(int));
}

int main(int argc, char *argv[])
{
	test_case_0();
	test_case_1();
	test_case_2();
	test_case_3();
	test_case_4();
	return 0;
}

