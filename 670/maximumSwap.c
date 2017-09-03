#include <leetcode.h>

int maximumSwap(int num)
{
	int i, j, n[10] = {0}, size = 0, max, swap;

	while (num) {
		n[size++] = num % 10;
		num /= 10;
	}

	for (i = size - 1; i; i--) {
		if (n[i] == 9)
			continue;
		for (j = 0, max = i; j < i; j++) {
			if (i == j)
				continue;
			if (n[j] <= n[i])
				continue;
			if (n[j] > n[max])
				max = j;
		}
		if (max != i) {
			j = n[i];
			n[i] = n[max];
			n[max] = j;
			break;
		}
	}

	num = 0;
	for (i = size - 1; i >= 0; i--) {
		num *= 10;
		num += n[i];
	}

	return num;
}

void tc_0(void)
{
	printf("7236\n%d\n\n", maximumSwap(2736));
	printf("9973\n%d\n\n", maximumSwap(9973));
	printf("99213\n%d\n\n", maximumSwap(91293));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

