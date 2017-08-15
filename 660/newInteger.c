#include <leetcode.h>

int newInteger(int n)
{
	int i, nth, num;
	unsigned int chk_num, chk_nth;
	static int init = 0, nums[10], skips[10], nths[10];

	if (n < 9)
		return n;

	if (!init) {
		nums[0] = 1;
		skips[0] = 0;
		nths[0] = 1;
		for (i = 1; i < 10; i++) {
			nums[i] = nums[i - 1] * 10;
			skips[i] = 9 * skips[i - 1] + nums[i - 1];
			nths[i] = nums[i] - skips[i];
		}
		init = 1;
	}

	for (i = 0; i < 10 && nths[i] < n; i++);

	if (i < 10) {
		if (nths[i] == n)
			return nums[i];
		i--;
	} else {
		i = 9;
	}

	nth = nths[i];
	num = nums[i];
	while (1) {
		chk_nth = (unsigned int)nth + (unsigned int)nths[i];
		chk_num = (unsigned int)num + (unsigned int)nums[i];
		if (chk_nth == (unsigned int)n)
			break;
		if (chk_nth > (unsigned int)n) {
			i--;
			continue;
		}
		if (chk_num >= (unsigned int)((1 << 31)))
			return INT_MAX;
		nth = chk_nth;
		num = chk_num;
	}

	return chk_num;
}

void tc_0(void)
{
	printf("457301372\n%d\n\n", newInteger(200000000));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

