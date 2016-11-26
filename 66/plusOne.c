#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
	int i, j, c, *rDigits;

	for (i = digitsSize - 1, c = 1; i >= 0; i--)
		c = (c + digits[i]) / 10;

	rDigits = malloc(sizeof(*rDigits) * (digitsSize + c));
	*returnSize = digitsSize + c;

	for (i = digitsSize + c - 1, j = digitsSize - 1, c = 1; j >= 0; i--, j--) {
		rDigits[i] = (c + digits[j]) % 10;
		c = (c + digits[j]) / 10;
	}

	if (c)
		rDigits[0] = c;

	return rDigits;
}


