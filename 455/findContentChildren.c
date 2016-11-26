#include <stdio.h>
#include <stdlib.h>


int findContentChildren(int* g, int gSize, int* s, int sSize)
{
	int i, j;

	int cmp(const void *a, const void *b) {
		const int *ia = a, *ib = b;
		return (*ia - *ib);
	}

	qsort(g, gSize, sizeof(*g), cmp);
	qsort(s, sSize, sizeof(*s), cmp);

	for (i = 0, j = 0; i < sSize && j < gSize; i++) {
		if (s[i] >= g[j])
			j++;
	}

	return j;
}

