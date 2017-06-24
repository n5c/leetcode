#include <leetcode.h>

char* reverseWords(char* s)
{
	char *ws, *we, *str;

	str = s;
	ws = str;
	we = str;
	while (1) {
		if (*str == ' ' || !*str) {
			we = (str - 1);
			while (ws < we) {
				char tmp = *ws;
				*ws = *we;
				*we = tmp;
				ws++;
				we--;
			}
			ws = str + 1;

			if (!*str)
				break;
		}
		str++;
	}

	return strdup(s);
}

void tc_0(void)
{
	char s[] = "Let's take LeetCode contest";
	char *result = reverseWords(s);
	printf("%s\n", result);
	free(result);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

