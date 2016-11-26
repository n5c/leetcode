#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

bool isHappy(int n)
{
	int i, _n, sum;
	static int *chk = NULL, chksz = 1024;

	if (!chk) {
		chk = calloc(sizeof(*chk), chksz);
		chk[0] = -1;
		chk[1] = 1;
	}

	while (1) {
		_n = n;
		sum = 0;
		while (n) {
			sum += (int)pow((double)(n % 10), (double)2);
			n /= 10;
		}
		n = sum;

		if (_n >= chksz)
			continue;

		if (!chk[n]) {
			chk[n] = _n;
		} else if (chk[n] >= 1) {
			int j, k;
			k = ((chk[n] == 1) ? 1 : -1);
			i = chk[_n];
			chk[_n] = k;
			while ((chk[i] > 1) && (chk[i] < chksz)) {
				j = chk[i];
				chk[i] = k;
				i = j;
			}
			chk[i] = k;
			if (k == 1)
				return true;
			return false;
		} else if (chk[n] <= -1) {
			return false;
		}
	}

	return true;
}

void test_case_0(void)
{
	int n = 19;
	printf("19\n");
	printf("expect: true\n");
	printf("%s\n\n", isHappy(n) ? "true" : "false");
}

void test_case_1(void)
{
	int n = 1;
	printf("1\n");
	printf("expect: true\n");
	printf("%s\n\n", isHappy(n) ? "true" : "false");
}

void test_case_2(void)
{
	int n = 44;
	printf("44\n");
	printf("expect: true\n");
	printf("%s\n\n", isHappy(n) ? "true" : "false");
}

void test_case_3(void)
{
	int n = 8;
	printf("8\n");
	printf("expect: false\n");
	printf("%s\n\n", isHappy(n) ? "true" : "false");
}

void test_case_4(void)
{
	int n = 888;
	printf("888\n");
	printf("expect: true\n");
	printf("%s\n\n", isHappy(n) ? "true" : "false");
}

void test_case_5(void)
{
	int n;
	for (n = 1; n < 100000000; n++) {
		// printf("=====> %d\n", n);
		//printf("expect: false\n");
		//printf("<===== %s\n", isHappy(n) ? "true" : "false");
		isHappy(n);
	}
}

int main(int argc, char *argv[])
{
	//test_case_0();
	//test_case_1();
	//test_case_2();
	//test_case_3();
	//test_case_4();
	test_case_5();
	return 0;
}

