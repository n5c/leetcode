#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int divide(int dividend, int divisor)
{
	int i, j, count = 0, neg = 0;
	if (!divisor)
		return INT_MAX;

	if (divisor == INT_MIN) {
		if (dividend == INT_MIN)
			return 1;
		return 0;
	}

	if (dividend == INT_MIN) {
		if (divisor == 1)
			return dividend;
		else if (divisor == -1)
			return INT_MAX;
		else if (divisor > 0) {
			neg++;
		} else /* if (divisor < 0) */ {
			divisor = -divisor;
		}
		dividend += divisor;
		dividend = -dividend;
		count++;
	} else {
		if (dividend < 0) {
			dividend = -dividend;
			neg++;
		}
		if (divisor < 0) {
			divisor = -divisor;
			neg++;
		}
	}

	if (divisor == 1) {
		count = dividend;
	} else {
		i = 1;
		while (divisor) {
			if (dividend == divisor) {
				count += i;
				break;
			} else if (dividend < divisor) {
				divisor >>= 1;
				i >>= 1;
				continue;
			} /* else */
			dividend = dividend - divisor;
			count += i;
			if (!(divisor & 0xc0000000)) {
				divisor <<= 1;
				i <<= 1;
			}
		}
	}
	return (count * ((neg == 1) ? -1 : 1));
}

void test_case_0()
{
	printf("%d, %d\n", INT_MIN, INT_MIN);
	printf("%d\n", INT_MIN / INT_MIN);
	printf("%d\n\n", divide(INT_MIN, INT_MIN));

	printf("%d, %d\n", INT_MIN, -123);
	printf("%d\n", INT_MIN / -123);
	printf("%d\n\n", divide(INT_MIN, -123));

	printf("%d, %d\n", INT_MIN, -1);
	printf("%d\n", /* INT_MIN / -1 */ INT_MAX);
	printf("%d\n\n", divide(INT_MIN, -1));

	printf("%d, %d\n", INT_MIN, 1);
	printf("%d\n", INT_MIN / 1);
	printf("%d\n\n", divide(INT_MIN, 1));

	printf("%d, %d\n", INT_MIN, 123);
	printf("%d\n", INT_MIN / 123);
	printf("%d\n\n", divide(INT_MIN, 123));

	printf("%d, %d\n", INT_MIN, INT_MAX);
	printf("%d\n", INT_MIN / INT_MAX);
	printf("%d\n\n", divide(INT_MIN, INT_MAX));
}

void test_case_1()
{
	int dividend, divisor;

	dividend = -123456789;
	divisor = -1234;
	printf("%d, %d\n", dividend, divisor);
	printf("%d\n", dividend / divisor);
	printf("%d\n\n", divide(dividend, divisor));

	dividend = -123456789;
	divisor = -1;
	printf("%d, %d\n", dividend, divisor);
	printf("%d\n", dividend / divisor);
	printf("%d\n\n", divide(dividend, divisor));

	dividend = -123456789;
	divisor = 1;
	printf("%d, %d\n", dividend, divisor);
	printf("%d\n", dividend / divisor);
	printf("%d\n\n", divide(dividend, divisor));

	dividend = -123456789;
	divisor = 1234;
	printf("%d, %d\n", dividend, divisor);
	printf("%d\n", dividend / divisor);
	printf("%d\n\n", divide(dividend, divisor));
}

void test_case_2()
{
	int dividend, divisor;

	dividend = INT_MAX;
	divisor = -1234;
	printf("%d, %d\n", dividend, divisor);
	printf("%d\n", dividend / divisor);
	printf("%d\n\n", divide(dividend, divisor));

	dividend = INT_MAX;
	divisor = -1;
	printf("%d, %d\n", dividend, divisor);
	printf("%d\n", dividend / divisor);
	printf("%d\n\n", divide(dividend, divisor));

	dividend = INT_MAX;
	divisor = 1;
	printf("%d, %d\n", dividend, divisor);
	printf("%d\n", dividend / divisor);
	printf("%d\n\n", divide(dividend, divisor));

	dividend = INT_MAX;
	divisor = 2;
	printf("%d, %d\n", dividend, divisor);
	printf("%d\n", dividend / divisor);
	printf("%d\n\n", divide(dividend, divisor));

	dividend = INT_MAX;
	divisor = 1234;
	printf("%d, %d\n", dividend, divisor);
	printf("%d\n", dividend / divisor);
	printf("%d\n\n", divide(dividend, divisor));
}

void test_case_3()
{
	int dividend = INT_MAX, divisor = 2;
	printf("%d, %d\n", dividend, divisor);
	printf("%d\n", dividend / divisor);
	printf("%d\n\n", divide(dividend, divisor));
}

int main(int argc, char *argv[])
{
	test_case_0();
	test_case_1();
	test_case_2();
	test_case_3();
	return 0;
}

