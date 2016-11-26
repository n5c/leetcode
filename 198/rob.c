#include <stdio.h>

int rob(int* nums, int numsSize)
{
	int i, j, k, l, m, count[20] = {0}, choose[20] = {0};

	if (!numsSize)
		return 0;
	if (numsSize == 1)
		return nums[0];
	if (numsSize == 2)
		return (nums[0] > nums[1] ? nums[0] : nums[1]);

	count[0] = 0;
	count[1] = nums[0];
	count[2] = nums[1];
	choose[0] = 0;
	choose[1] = 1;
	choose[2] = 2;

	for (i = 2; i < numsSize; i++) {
		k = ((i < 10) ? i + 1 : 10);
		for (j = 0; j < 10 && j <= i; j++) {
			if (choose[j] == 0) {
				count[j] += nums[i];
				choose[j] = 2;
			} else if (choose[j] == 1) {
				choose[j] = 0;
				count[k] = count[j] + nums[i];
				choose[k] = 2;
				k++;
			} else if (choose[j] == 2) {
				choose[j] = 1;
			}
		}

		for (j = 0; j < k - 1; j++) {
			for (l = j + 1; l < k; l++) {
				if (count[l] <= count[j])
					continue;
				m = count[l];
				count[l] = count[j];
				count[j] = m;

				m = choose[l];
				choose[l] = choose[j];
				choose[j] = m;
			}
		}
	}

	return count[0];
}

void test_case_0()
{
	int nums[] = {6,6,4,8,4,3,3,10};
	int numsSize = sizeof(nums)/sizeof(*nums);
	printf("27\n");
	printf("%d\n\n", rob(nums, numsSize));
}

void test_case_1()
{
	int nums[] = {6,6,6,1,2,3,3,10};
	int numsSize = sizeof(nums)/sizeof(*nums);
	printf("25\n");
	printf("%d\n\n", rob(nums, numsSize));
}

void test_case_2()
{
	int nums[] = {6,6,6,3,2,1,3,10};
	int numsSize = sizeof(nums)/sizeof(*nums);
	printf("24\n");
	printf("%d\n\n", rob(nums, numsSize));
}

void test_case_3()
{
	int nums[] = {1,1,3,6,7,10,7,1,8,5,9,1,4,4,3};
	int numsSize = sizeof(nums)/sizeof(*nums);
	printf("42\n");
	printf("%d\n\n", rob(nums, numsSize));
}

int main(int argc, char *argv[])
{
	test_case_0();
	test_case_1();
	test_case_2();
	test_case_3();
	return 0;
}

