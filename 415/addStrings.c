#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addStrings(char* num1, char* num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int i, j, c;
	char *si, *sj;

	if (!len1)
		return num2;
	if (!len2)
		return num1;

	if (len1 >= len2) {
		i = len1 - 1;
		j = len2 - 1;
		si = num1;
		sj = num2;
	} else {
		i = len2 - 1;
		j = len1 - 1;
		si = num2;
		sj = num1;
	}

	c = 0;
	while ((i >= 0) && (j >= 0)) {
		si[i] = si[i] + sj[j] - '0' + c;
		if (si[i] > '9') {
			si[i] -= 10;
			c = 1;
		} else {
			c = 0;
		}
		i--;
		j--;
	}

	while ((i >= 0) && c) {
		si[i] += c;
		if (si[i] > '9') {
			si[i] -= 10;
			c = 1;
		} else {
			c = 0;
		}
		i--;
	}

	len1 = ((len1 >= len2) ? len1 : len2);
	sj = malloc(sizeof(*sj) * (len1 + c + 1));
	if (c)
		sj[0] = '1';
	memcpy((sj + c), si, len1);
	sj[len1 + c] = 0;

	return sj;
}

void test_case_0(void)
{
	char num1[] = "0";
	char num2[] = "0";
	printf("0\n");
	printf("0\n");
	printf("expect: 0\n");
	printf("%s\n", addStrings(num1, num2));
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

