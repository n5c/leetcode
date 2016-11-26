#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize)
{
	char *prefix, prefixLen = 0;
	int i, j;

	if (strsSize)
		prefixLen = strlen(strs[0]);

	prefix = malloc(prefixLen + 1);

	if (prefixLen <= 0) {
		prefix[0] = 0;
		return prefix;
	}

	memcpy(prefix, strs[0], prefixLen);

	for (i = 1; (i < strsSize) && (prefixLen > 0); i++) {
		if (strlen(strs[i]) < prefixLen)
			prefixLen = strlen(strs[i]);
		for (j = 0; (j < prefixLen) && (prefix[j] == strs[i][j]); j++);
		prefixLen = j;
	}

	prefix[prefixLen] = 0;

	return prefix;
}

int main(int argc, char *argv[])
{
	return 0;
}

