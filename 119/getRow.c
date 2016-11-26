#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize)
{
	int i, j, *row;

	row = malloc(sizeof(*row) * (rowIndex + 1));
	*returnSize = (rowIndex + 1);

	row[0] = 1;
	if (rowIndex == 0)
		return row;

	row[1] = 1;
	if (rowIndex == 1)
		return row;

	row[1] = 2;
	row[2] = 1;
	if (rowIndex == 2)
		return row;

	for (i = 3; i <= rowIndex; i++) {
		row[i] = 1;
		for (j = i - 1; j; j--)
			row[j] = row[j] + row[j - 1];
	}

	return row;
}



