#include <stdio.h>

int lengthOfLongestSubstring(char* s)
{
	int length = 0, longest = 0;
	char *ptr[256] = {0};
	char *start = s;

	while (*s != 0) {
		if (ptr[*s] && (ptr[*s] >= start)) {
			length = (s - ptr[*s]);
			start = (ptr[*s] + 1);
			ptr[*s] = s;
			s++;
			continue;
		}

		ptr[*s] = s;
		s++;
		length++;
		if (length > longest)
			longest = length;
	}

	return longest;
}

void test_case_0(void)
{
	printf("3: %d\n", lengthOfLongestSubstring("abcabcbb"));
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

