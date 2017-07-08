#include <leetcode.h>

bool judgeSquareSum(int c)
{
	int i, j, k, l;
	j = sqrt(c);
	for (i = 0; i <= j; i++) {
		k = c - (i * i);
		if (k < 0)
			break;
		j = sqrt(k);
		if (j * j == k)
			return true;
		l = sqrt(c - (j * j)) - 1;
		if (l >= i)
			i = l;

	}
	return false;

}

void tc_0(void)
{
	char *bstr[] = {"false", "true"};
	printf("true\n%s\n\n", bstr[judgeSquareSum(5)]);
	printf("true\n%s\n\n", bstr[judgeSquareSum(1855135872)]);
	printf("true\n%s\n\n", bstr[judgeSquareSum(16)]);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

