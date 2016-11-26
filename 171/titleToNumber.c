#include <stdio.h>

int titleToNumber(char* s)
{
	int num;
	num = 0;
	while (*s) {
		num *= 26;
		num += (*s - ((*s <= 'Z') ? 'A' : 'a') + 1);
		s++;
	}

	return num;
}

void test_case_0(void)
{
	printf("A: 1\n");
	printf("%d\n", titleToNumber("A"));
}

void test_case_1(void)
{
	printf("AA: 27\n");
	printf("%d\n", titleToNumber("AA"));
}

void test_case_2(void)
{
	printf("aaac: ??\n");
	printf("%d\n", titleToNumber("aaac"));
}

int main(int argc, char *argv[])
{
	test_case_0();
	test_case_1();
	test_case_2();
	return 0;
}

