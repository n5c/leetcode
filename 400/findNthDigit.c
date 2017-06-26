#include <leetcode.h>

int findNthDigit(int n)
{
	long long i, j, k, l, m;
	char str[10];

	if (n < 10)
		return n;

	i = 10;
	j = 10;
	k = 10;
	l = 2;
	while (i < n) {
		i += 9 * k * l;
		j += 9 * k;
		k *= 10;
		l++;
	}

	k /= 10;
	l--;
	i -= 9 * k * l;
	j -= 9 * k;

	while (k) {
		while (i <= n) {
			i += k * l;
			j += k;
		}
		i -= k * l;
		j -= k;
		k /= 10;
	}

	l = n - i;
	snprintf(str, 10, "%d", (int)j);
	j = str[l] - '0';

	return j;
}

void tc_0(void)
{
	printf("2: %d\n", findNthDigit(2147483647));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

