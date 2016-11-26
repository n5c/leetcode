#include <stdio.h>

int reverse(int x)
{
	int r, minus, tmp;

	minus = 0;
	if (x < 0) {
		minus = 1;
		x *= -1;
	}

	r = x % 10;
	x /= 10;
	while (x) {
		r *= 10;
		r += x % 10;
		if ((r % 10) != (x % 10))
			return 0;
		x /= 10;
	}

	if (minus)
		r *= -1;

	return r;
}

void test_case_0(void)
{
	printf("987654321: %d\n", reverse(123456789));
}

void test_case_1(void)
{
	printf("0: %d\n", reverse(1234567899));
}

void test_case_2(void)
{
	printf("-321: %d\n", reverse(-123));
}

int main(int argc, char *argv[])
{
	test_case_0();
	test_case_1();
	test_case_2();
	return 0;
}

