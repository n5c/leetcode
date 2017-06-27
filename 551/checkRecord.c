#include <leetcode.h>

bool checkRecord(char* s)
{
	int a = 0, l = 0;
	while (*s) {
		if (*s == 'A') {
			if (a)
				return false;
			a++;
		}

		if (*s == 'L') {
			if (l >= 2)
				return false;
			l++;
		} else {
			l = 0;
		}

		s++;
	}
	return true;
}

void tc_0(void)
{
	printf("true\n%s\n",
		checkRecord("PPALLP") ? "true" : "false");
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

