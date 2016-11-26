#include <stdio.h>
#include <stdlib.h>

int* singleNumber(int* nums, int numsSize, int* returnSize)
{
	return NULL;
}

void test_case_0()
{
	int nums[] = {
		1,2,3,4,5,4,3,8,2,7,7,1,100001,100001,65541,65541
	};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int *returnNums, returnSize;

	returnNums = singleNumber(nums, numsSize, &returnSize);
	printf("%d, %d\n", returnNums[0], returnNums[1]);
	free(returnNums);
}

void test_case_1()
{
	int nums[] = {
		  29328859,  1466838361,   -66079248,   926571150,  1456000429,
		 926571150,  1536309894,  -182157937,  -391092726,  1518731260,
		 -66079248, -1116874613, -1703212692, -1116874613, -1321264512,
		-816411092,  -483719306,   110721554,    29328859,  -357092863,
		-391092726,  -357092863,  1466838361, -1703212692, -1321264512,
		1518731260,  1536309894,   640411520,  -182157937,  -816411092,
		1456000429,  -483719306
	};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int *returnNums, returnSize;

	returnNums = singleNumber(nums, numsSize, &returnSize);
	printf("%d, %d\n", returnNums[0], returnNums[1]);
	free(returnNums);
}

int main(int argc, char *argv[])
{
	test_case_1();
	return 0;
}

