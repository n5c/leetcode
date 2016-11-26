#include <stdio.h>

#define bool int
#define true 1
#define false 0

bool repeatedSubstringPattern(char* str)
{
	int i, j;

	if (!str || !*str)
		return false;

	for (i = 1, j = 0; str[i]; i++) {
		if (str[i] != str[j]) {
			if (j)
				i--;
			j = 0;
		}
		else
			j++;
	}

	if (i == 1)
		return false;

	if (str[j] != str[0])
		return false;

	if (j < (i >> 1))
		return false;

	return true;
}

void test_case_0(void)
{
	char str[1024];
	snprintf(str, 1024, "abab");
	printf("1\n");
	printf("%d\n\n", repeatedSubstringPattern(str));

	snprintf(str, 1024, "aba");
	printf("0\n");
	printf("%d\n\n", repeatedSubstringPattern(str));

	snprintf(str, 1024, "abcabcabcabc");
	printf("1\n");
	printf("%d\n\n", repeatedSubstringPattern(str));

	snprintf(str, 1024, "abcdefghimnjklmn");
	printf("0\n");
	printf("%d\n\n", repeatedSubstringPattern(str));

	snprintf(str, 1024, "abcdefghgijklmnopqzxy");
	printf("0\n");
	printf("%d\n\n", repeatedSubstringPattern(str));

	snprintf(str, 1024, "ababaaaaababaaaaababaaaaababaaaa");
	printf("1\n");
	printf("%d\n\n", repeatedSubstringPattern(str));

	snprintf(str, 1024, "ababbaaaaaababbaaaaaababbaaaaaababbaaaaa"
			    "ababbaaaaaababbaaaaaababbaaaaaababbaaaaa"
			    "ababbaaaaaababbaaaaa");
	printf("1\n");
	printf("%d\n\n", repeatedSubstringPattern(str));
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

