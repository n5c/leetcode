#include <leetcode.h>

int lengthOfLastWord(char* s)
{
	int i = 0, len = 0;
	if (s[i]) {
		if (s[i] != ' ')
			len++;
		i++;
	}
	while (s[i]) {
		if (s[i] != ' ') {
			if (s[i - 1] == ' ')
				len = 0;
			len++;
		}
		i++;
	}
	return len;
}

void tc_0(void)
{
	printf("0\n%d\n\n", lengthOfLastWord(""));
	printf("0\n%d\n\n", lengthOfLastWord("  "));
	printf("5\n%d\n\n", lengthOfLastWord("Hello World "));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

