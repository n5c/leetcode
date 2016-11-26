#include <stdio.h>

int getSum(int a, int b)
{
	int _a, _b, c, sum, tmp;

	c = 0;
	sum = 0;
	tmp = 0x1;
	while (tmp && ((a & ~(tmp - 1)) || (b & ~(tmp - 1)))) {
		_a = a & tmp;
		_b = b & tmp;
		sum |= ((_a ^ _b) ^ c);
		c = (((_a & _b) | ((_a ^ _b) & c)) << 1);
		tmp <<= 1;
	}

	sum |= c;

	return sum;
}

void test_case_0(void)
{
	printf("3: %d\n", getSum(1,2));
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

