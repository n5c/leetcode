#include <leetcode.h>

char* addBinary(char* a, char* b)
{
	int i, j, k, c;
	char *sums, *_a, *_b;

	if (!a || !b || !*a || !*b) {
		if (a && *a)
			return strdup(a);
		if (b && *b)
			return strdup(b);
		return strdup("0");
	}

	for (i = 0; a[i]; i++);
	for (j = 0; b[j]; j++);

	_a = a;
	_b = b;
	if (i > j) {
		k = i;
		i = j;
		j = k;
		_a = b;
		_b = a;
	}

	sums = malloc(sizeof(*sums) * (j + 2));

	i--;
	j--;
	k = 0;
	c = 0;
	while (i >= 0) {
		c += _a[i--] + _b[j--] - ((int)'0' << 1);
		sums[k] = (char)(c & 0x1) + '0';
		k++;
		c >>= 1;
	}
	while (j >= 0) {
		c += _b[j--] - (int)'0';
		sums[k++] = (char)(c & 0x1) + '0';
		c >>= 1;
	}
	if (c)
		sums[k++] = '1';
	sums[k] = 0;
	for (i = 0, j = k - 1; i < j; i++, j--) {
		k = (int)sums[i];
		sums[i] = sums[j];
		sums[j] = (char)k;
	}

	return sums;
}

void tc_0(void)
{
	char *sum;

	sum = addBinary("0", "0");
	printf("0\n%s\n\n", sum);
	free(sum);

	sum = addBinary("111", "111");
	printf("1110\n%s\n\n", sum);
	free(sum);

	sum = addBinary("100", "1");
	printf("101\n%s\n\n", sum);
	free(sum);

	sum = addBinary("111", "1");
	printf("1000\n%s\n\n", sum);
	free(sum);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

