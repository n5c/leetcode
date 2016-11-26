#include <stdio.h>

char findTheDifference(char* s, char* t)
{
	    int count[256] = {0};

	        while (*s) count[*s++]++;
		    while (*t) {
			            count[*t]--;
				            if (count[*t] == -1)
						                break;
					            t++;
						        }
		        return *t;
}

void test_case_0(void)
{
	printf("a: %c\n",
		findTheDifference("ababa",
				  "abaaba"));
}

void test_case_1(void)
{
	printf("b: %c\n",
		findTheDifference("",
				  "b"));
}

void test_case_2(void)
{
	printf("g: %c\n",
		findTheDifference("abcdef",
				  "abcdefg"));
}

int main(int argc, char *argv[])
{
	test_case_0();
	test_case_1();
	test_case_2();
	return 0;
}

