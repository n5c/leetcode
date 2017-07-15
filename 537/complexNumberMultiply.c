#include <leetcode.h>

char* complexNumberMultiply(char* a, char* b)
{
	char s[80];
	int ia1, ia2, ib1, ib2, ic1, ic2;
	sscanf(a, "%d+%di", &ia1, &ia2);
	sscanf(b, "%d+%di", &ib1, &ib2);
	ic1 = (ia1 * ib1) - (ia2 * ib2);
	ic2 = (ia1 * ib2) + (ia2 * ib1);
	snprintf(s, 80, "%d+%di", ic1, ic2);
	return strdup(s);

}

void tc_0(void)
{
	char *s = complexNumberMultiply(
			"1+1i",
			"1+1i"
			);
	printf("0+2i\n%s\n\n", s);
	free(s);
}

void tc_1(void)
{
	char *s = complexNumberMultiply(
			"1+1i",
			"1+-1i"
			);
	printf("2+0i\n%s\n\n", s);
	free(s);
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	return 0;
}

