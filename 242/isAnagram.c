#include <stdio.h>

#define bool int
#define true 1
#define false 0

bool isAnagram(char* s, char* t)
{
	int i, count[256] = {0};

	while (*s)
		count[*s++]++;

	while (*t) {
		count[*t]--;
		if (count[*t] < 0)
			return false;
		t++;
	}

	for (i = 0; i < 256; i++) {
		if (!count[i])
			continue;
		return false;
	}

	return true;
}

void test_case_0(void)
{
	printf("\"\", \"\": true\n");
	printf("%s\n", isAnagram("", "") ? "true" : "false");
}

void test_case_1(void)
{
	printf("\"abcd\", \"\": false\n");
	printf("%s\n", isAnagram("abcd", "") ? "true" : "false");
}

void test_case_2(void)
{
	printf("\"\", \"abcd\": false\n");
	printf("%s\n", isAnagram("", "abcd") ? "true" : "false");
}

void test_case_3(void)
{
	printf("\"abcd\", \"dbca\": true\n");
	printf("%s\n", isAnagram("abcd", "dbca") ? "true" : "false");
}

void test_case_4(void)
{
	printf("\"ddbca\", \"abcd\": false\n");
	printf("%s\n", isAnagram("ddbca", "abcd") ? "true" : "false");
}

int main(int argc, char *argv[])
{
	test_case_0();
	test_case_1();
	test_case_2();
	test_case_3();
	test_case_4();
	return 0;
}
