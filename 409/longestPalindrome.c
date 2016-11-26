#include <stdio.h>

int longestPalindrome(char* s)
{
	int i, l, count[256] = {0};

	while (*s) count[*s++]++;

	l = 0;
	for (i = 0; i < 256; i++) {
		if (!count[i])
			continue;
		if (count[i] & 0x1) {
			l += count[i];
			i++;
			break;
		}
		l += count[i];
	}

	for (; i < 256; i++) {
		if (!count[i])
			continue;
		if (count[i] & 0x1)
			l -= 1;
		l += count[i];
	}

	return l;
}


