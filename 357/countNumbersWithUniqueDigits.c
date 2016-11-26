#include <stdio.h>
#include <math.h>

int countNumbersWithUniqueDigits(int n)
{
	int i, j, k, l, m, counts[n + 1];

	counts[0] = 1;
	counts[1] = 10;

	for (i = 2; i <= n; i++) {
		k = 9 * 9;
		l = 8;
		for (j = 2; j < i; j++, l--)
			k *= l;
		counts[i] = k + counts[i - 1];
		printf("%d: %d = %d + %d\n",
			i, counts[i], k, counts[i - 1]);
	}

	return counts[n];
}

void test_case_0()
{
	printf("%d\n", countNumbersWithUniqueDigits(3));
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

