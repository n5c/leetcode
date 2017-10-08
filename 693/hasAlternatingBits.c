#include <leetcode.h>

bool hasAlternatingBits(int n)
{
	int bit = n & 1;
	while (n) {
		if ((n & 1) != bit)
			return false;
		n >>= 1;
		bit ^= 1;
	}
	return true;
}

void tc_0(void)
{
	char *boolstr[] = {"false","true"};
	printf("true\n%s\n\n", boolstr[hasAlternatingBits(5)]);
	printf("false\n%s\n\n", boolstr[hasAlternatingBits(7)]);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

