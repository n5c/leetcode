#include <leetcode.h>

int findLUSlength(char* a, char* b)
{
	int i, j;
	for (i = 0; a[i]; i++);
	for (j = 0; b[j]; j++);
	if (i == j) {
		for (i = 0; a[i]; i++)
			if (a[i] != b[i])
				return j;
		return -1;
	} else if (i > j) {
		return i;
	} else
		return j;
}

void tc_0(void)
{
	char *a = "aba";
	char *b = "cdc";
	printf("%d\n", findLUSlength(a, b));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

