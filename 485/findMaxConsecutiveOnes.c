#include <leetcode.h>

int findMaxConsecutiveOnes(int* nums, int numsSize)
{
	int i, cons, max;
	for (i = 0, cons = 0, max = 0; i < numsSize; i++) {
		if (nums[i]) {
			cons++;
		} else {
			if (cons) {
				if (cons > max)
					max = cons;
				cons = 0;
			}
		}
	}

	if (cons > max)
		max = cons;

	return max;
}

void tc_1(void)
{
	int nums[] = {1,0,1,1,0,1};
	int numsSize = sizeof(nums)/sizeof(*nums);
	printf("%d\n", findMaxConsecutiveOnes(nums, numsSize));
}

void tc_0(void)
{
	int nums[] = {1};
	int numsSize = sizeof(nums)/sizeof(*nums);
	printf("%d\n", findMaxConsecutiveOnes(nums, numsSize));
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	return 0;
}

