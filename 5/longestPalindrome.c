#include <leetcode.h>

char* longestPalindrome(char* s)
{
	char *palindrome, *p, *left, *right, *start;
	int length = 0, longest = 0;

	start = p = s;
	longest = 1;
	while (*p) {

		if (*(p - 1) == *(p + 1)) {
			left = p - 1;
			right = p + 1;
			length = 1;
			while ((left >= s) && (*left == *right)) {
				length+=2;
				left--;
				right++;
			}
			if (length > longest) {
				start = left + 1;
				longest = length;
			}
		}

		if (*p == *(p + 1)) {
			left = p;
			right = p + 1;
			length = 0;
			while ((left >= s) && (*left == *right)) {
				length+=2;
				left--;
				right++;
			}
			if (length > longest) {
				start = left + 1;
				longest = length;
			}
		}

		p++;
	}

	palindrome = malloc(longest + 1);
	memcpy(palindrome, start, longest);
	palindrome[longest] = 0;

	return palindrome;
}

void tc_1(void)
{
	char s[] = "cbbd";
	char *p = longestPalindrome(s);
	printf("%s\n", p);
	free(p);
}

void tc_0(void)
{
	char s[] = "babad";
	char *p = longestPalindrome(s);
	printf("%s\n", p);
	free(p);
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	return 0;
}

