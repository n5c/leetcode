#include <stdio.h>

int majorityElement(int* nums, int numsSize)
{
	int i, major, count;

	major = nums[0];
	count = 1;
	for (i = 1; i < numsSize; i++) {
		if (count == 0) {
			major = nums[i];
			count = 1;
		} else if (major == nums[i]) {
			count++;
		} else /* if (major != nums[i]) */ {
			count--;
		}
	}

	return major;
}

void test_case_0()
{
	int nums[] = {
		1,2,1,2,1
	};
	int size = sizeof(nums)/sizeof(int);
	printf("\"1,2,1,2,1\":1\n");
	printf("%d\n", majorityElement(nums, size));
}

void test_case_1()
{
	int nums[] = {
		1,3,2,3,1,2,3,2,3,1,3,2,3
	};
	int size = sizeof(nums)/sizeof(int);
	printf("\"1,3,2,3,1,2,3,2,3,1,3,2,3\":1\n");
	printf("%d\n", majorityElement(nums, size));
}

void test_case_2()
{
	int nums[] = {
		1,2,1,2,1
	};
	int size = sizeof(nums)/sizeof(int);
	printf("\"1,2,1,2,1\":1\n");
	printf("%d\n", majorityElement(nums, size));
}

int main(int argc, char *argv[])
{
	test_case_1();
	return 0;
}

