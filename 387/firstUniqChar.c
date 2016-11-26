#include <stdio.h>

int firstUniqChar(char* s)
{
	int i, min, count[256];

	for (i = 0; i < 256; i++)
		count[i] = -1;

	for (i = 0; s[i]; i++) {
		if (count[s[i]] == -1)
			count[s[i]] = i;
		else
			count[s[i]] = -2;
	}

	min = -1;
	for (i = 0; i < 256; i++) {
		if (count[i] < 0)
			continue;
		if (min == -1 || count[i] < min)
			min = count[i];
	}

	return min;
}

void test_case_0(void)
{
	printf("leetcode: 0\n");
	printf("%d\n", firstUniqChar("leetcode"));
}

void test_case_1(void)
{
	printf("loveleetcode: 2\n");
	printf("%d\n", firstUniqChar("loveleetcode"));
}

void test_case_2(void)
{
	printf("leetcode: 0\n");
	printf("%d\n", firstUniqChar("leetcode"));
}

void test_case_3(void)
{
	printf("leetcode: 0\n");
	printf("%d\n", firstUniqChar("leetcode"));
}

int main(int argc, char *argv[])
{
	test_case_0();
	test_case_1();
	return 0;
}
