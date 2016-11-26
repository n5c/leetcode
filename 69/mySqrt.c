#include <stdio.h>
#include <math.h>
#include <unistd.h>

int mySqrt(int x)
{
	unsigned int sqrt, start, end, p;

	if (!x)
		return 0;

	if (x < 0)
		return -1;

	sqrt = 1;
	start = 0;
	end = 0;
	while (1) {
		p = sqrt * sqrt;
		if (p > x) {
			end = sqrt - 1;
			sqrt = (start + end) >> 1;
		} else if (p < x) {
			start = sqrt + 1;
			if (!end) {
				if (sqrt < 0x8000)
					sqrt <<= 1;
				else
					sqrt = 0x10000 - 1;
			} else {
				if (start > end)
					break;
				sqrt = (start + end >> 1);
			}
		} else {
			return sqrt;
		}
	}

	return sqrt;
}

void test_case_0()
{
	int x;

	x = 1223456789;
	printf("%f\n", sqrt(x));
	printf("%d\n\n", mySqrt(x));

	x = 123456789;
	printf("%f\n", sqrt(x));
	printf("%d\n\n", mySqrt(x));

	x = 1;
	printf("%f\n", sqrt(x));
	printf("%d\n\n", mySqrt(x));

	x = -4;
	printf("%f\n", sqrt(x));
	printf("%d\n\n", mySqrt(x));
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

