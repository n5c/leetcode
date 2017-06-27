#include <leetcode.h>

bool detectCapitalUse(char* word)
{
	int i = 0, chk_upper = 0, chk_lower = 0;
	while (word[i]) {
		if (word[i] >= 'a') {
			chk_lower++;
			if (chk_upper > 1)
				return false;
		} else {
			chk_upper++;
			if (chk_lower)
				return false;
		}
		i++;
	}
	return true;
}

void tc_0(void)
{
	printf("true : %s\n", detectCapitalUse("USA") ?
			"true" : "false");
	printf("false : %s\n", detectCapitalUse("FlaG") ?
			"true" : "false");
	printf("false : %s\n", detectCapitalUse("FFFFFFFFFFFFFFFFFFFFf") ?
			"true" : "false");
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

