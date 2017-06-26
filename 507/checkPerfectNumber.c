#include <leetcode.h>

bool checkPerfectNumber(int num)
{
	int i, j, k, n;

	if (num == 1)
		return false;

	k = (int)sqrt(num);
	for (i = 2, n = 1; i <= k && n <= num; i++) {
		if (num % i)
			continue;
		n += i;
		n += num / i;
	}

	return (n == num);
}

void tc_0(void)
{
	printf("true: %s\n", checkPerfectNumber(28) ? "true" : "false");
	printf("false: %s\n", checkPerfectNumber(36) ? "true" : "false");
	printf("false: %s\n", checkPerfectNumber(1) ? "true" : "false");
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

