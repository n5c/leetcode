#include <stdio.h>
#include <stdlib.h>

char* convert(char* s, int numRows)
{
	int i, j, k, l, size, offset[2];
	char *z;

	z = s;
	while (*z)z++;
	size = z - s;
	z = malloc(size + 1);

	l = 0;
	for (i = 0; i < numRows; i++) {
		offset[0] = offset[1] = numRows + (numRows - 2);
		if (!offset[0]) {
			offset[0] = offset[1] = 1;
		}
		else if (i && i < numRows - 1) {
			offset[0] -= (i * 2);
			offset[1] = (i * 2);
		}
		for (j = i, k = 0; j < size; j += offset[k], k ^= 1) {
			z[l] = s[j];
			l++;
		}
	}

	z[size] = 0;
	return z;
}

int main(int argc, char *argv[])
{
	return 0;
}

