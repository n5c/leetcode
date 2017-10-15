#include <leetcode.h>

int countBinarySubstrings(char* s)
{
	int i = 0, j = 0, count = 0, _0s = 0, _1s = 0;
	char *p = s;
	while (s[i]) {
		p = s + i;
		j = 1;
		while (s[i] == p[j]) ++j;
		if (s[i] == '0')
			_0s = j;
		else /* if (s[i] == '1') */
			_1s = j;
		count += ((_0s <= _1s) ? _0s : _1s);
		i += j;
	}
	return count;
}

void tc_0(void)
{
	printf("6\n%d\n\n", countBinarySubstrings("00110011"));
	printf("4\n%d\n\n", countBinarySubstrings("10101"));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

