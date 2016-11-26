#include <stdio.h>

int isPalindrome(int x)
{
	int m = x, n = 0;

	if (x < 0)
		return 0;

	while (m) {
		n = ((n * 10) + (m % 10));
		m /= 10;
	}

	return (n == x);
}

void test_case_0(void)
{
	printf("true: %s\n", (isPalindrome(123321) ? "true" : "false"));
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

