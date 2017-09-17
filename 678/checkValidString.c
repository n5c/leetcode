#include <leetcode.h>

bool checkValidString(char* s)
{
	int i, left = 0, right = 0, ast = 0;
	for (i = 0; s[i]; i++) {
		if (s[i] == '(')
			left++;
		else if (s[i] == ')')
			right++;
		else
			ast++;
		if (right > left + ast)
			return false;
	}
	for (i--, left = 0, right = 0, ast = 0; i >= 0; i--) {
		if (s[i] == '(')
			left++;
		else if (s[i] == ')')
			right++;
		else
			ast++;
		if (left > right + ast)
			return false;
	}
	return true;
}

void tc_0(void)
{
	printf("true\n%s\n\n", checkValidString("()") ?
			"true" : "false");
	printf("false\n%s\n\n", checkValidString(")*()") ?
			"true" : "false");
	printf("true\n%s\n\n", checkValidString("(*))") ?
			"true" : "false");
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

