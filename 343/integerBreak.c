#include <stdio.h>

int integerBreak(int n)
{
	int i, j, k, max;
	static int ib[60] = {0};

	ib[0] = 0;
	ib[1] = 1;
	ib[2] = 1;
	if ((n >= 0 && n <= 58) && ib[n])
		return ib[n];

	for (i = 3; i <= n; i++) {
		if (ib[i])
			continue;
		j = (i >> 1);
		max = ib[j];
		while (j < i) {
			k = i - j;
			if (k * ib[j] > max)
				max = k * ib[j];
			if (k * j > max)
				max = k * j;
			j++;
		}

		ib[i] = max;
	}

	return ib[n];
}

void test_case_0()
{
	printf("%d\n", integerBreak(10));
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

