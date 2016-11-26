#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int arrangeCoins(int n)
{
	unsigned int coin, row, start, end;

	if (n == 0)
		return 0;

	row = 1;
	coin = 0;
	start = 0;
	end = 0;
	while (coin != n) {
		if (row & 1)
			coin = row * ((row + 1) >> 1);
		else
			coin = (row >> 1) * (row + 1);
		if (coin < n) {
			if (!end) {
				start = (row >> 1) + 1;
				row <<= 1;
			} else {
				int tmp;
				start = row + 1;
				tmp = (start + end) >> 1;
				if (tmp == row)
					break;
				row = tmp;
			}
		} else if (coin > n) {
			end = row - 1;
			row = (start + end) >> 1;
		}
	}

	return row;
}

void test_case_0()
{
	int n = 123456789;
	printf("15712\n");
	printf("%d\n\n", arrangeCoins(n));

	n = 123441328;
	printf("15712\n");
	printf("%d\n\n", arrangeCoins(n));

	n = 0;
	printf("0\n");
	printf("%d\n\n", arrangeCoins(n));

	n = 1;
	printf("1\n");
	printf("%d\n\n", arrangeCoins(n));

	n = 3;
	printf("2\n");
	printf("%d\n\n", arrangeCoins(n));

	n = 1804289383;
	printf("60070\n");
	printf("%d\n\n", arrangeCoins(n));
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

