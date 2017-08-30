#include <leetcode.h>

int findKthNumber(int m, int n, int k)
{
	int i, j, lo, hi, mid, count;
	if (m > n) {
		i = m;
		m = n;
		n = i;
	}
	lo = 1;
	hi = m * n;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		i = mid / n;
		count = i * n;
		j = m;
		if (mid < j)
			j = mid;
		for (i = i + 1; i <= j; i++)
			count += mid / i;
		if (count < k)
			lo = mid + 1;
		else
			hi = mid - 1;
	}

	if (mid == lo) {
		while (1) {
			if (mid <= n || !(mid & 0x1))
				break;
			for (i = 3; i <= m && mid % i; i += 2);
			if (i <= m)
				break;
			mid++;
		}
	} else {
		while (1) {
			mid++;
			if (mid <= n || !(mid & 0x1))
				break;
			for (i = 3; i <= m && mid % i; i += 2);
			if (i <= m)
				break;
		}
	}
	return mid;
}


void tc_0(void)
{
	printf("126\n%d\n\n", findKthNumber(42, 34, 401));
	printf("24\n%d\n\n", findKthNumber(11, 13, 57));
	printf("3\n%d\n\n", findKthNumber(3, 3, 5));
	printf("312\n%d\n\n", findKthNumber(45, 12, 471));
	printf("2\n%d\n\n", findKthNumber(1, 3, 2));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

