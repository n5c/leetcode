#include <leetcode.h>

inline static bool isPalindromic(char *start, char *end)
{
	while (start < end) {
		if (*start != *end)
			break;
		start++;
		end--;

	}
	return (start >= end);

}

int countSubstrings(char* s)
{
	int i, j, count = 0;
	for  (i = 0; s[i]; i++) {
		count++;
		for (j = 0; j < i; j++)
			count += isPalindromic(&s[j], &s[i]);

	}
	return count;

}

void tc_0(void)
{
	printf("3\n%d\n\n", countSubstrings("abc"));
	printf("6\n%d\n\n", countSubstrings("aaa"));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

