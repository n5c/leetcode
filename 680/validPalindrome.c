#include <leetcode.h>

bool validPalindrome(char* s)
{
	int i, j, chk;
	for (i = 0; s[i]; ++i);
	for (j = i - 1, i = 0; i < j && s[i] == s[j]; i++, j--);
	if (i >= j)
		return true;
	chk = false;
	if (s[i + 1] == s[j]) {
		if (i + 2 >= j - 1)
			return true;
		if (s[i + 2] == s[j - 1]) {
			chk = true;
			i++;
		}
	}
	if (!chk) {
		if (s[i] != s[j - 1])
			return false;
		if (i + 1 >= j - 2)
			return true;
		if (s[i + 1] != s[j - 2])
			return false;
		j--;
	}
	for (i++, j--; i < j && s[i] == s[j]; i++, j--);
	if (i >= j)
		return true;
	return false;
}

void tc_0(void)
{
	printf("true\n%s\n\n",
			validPalindrome("abca") ?
			"true" : "false");
	printf("false\n%s\n\n",
			validPalindrome("abc") ?
			"true" : "false");
	printf("true\n%s\n\n",
			validPalindrome("cdccd") ?
			"true" : "false");
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

