#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes)
{
	int i, j, **pTriangle;

	if (!numRows)
		return NULL;

	pTriangle = malloc(sizeof(*pTriangle) * numRows);
	*columnSizes = malloc(sizeof(**columnSizes) * numRows);

	pTriangle[0] = malloc(sizeof(**pTriangle) * 1);
	pTriangle[0][0] = 1;
	(*columnSizes)[0] = 1;

	if (numRows == 1)
		return pTriangle;

	pTriangle[1] = malloc(sizeof(**pTriangle) * 2);
	pTriangle[1][0] = 1;
	pTriangle[1][1] = 1;
	(*columnSizes)[1] = 2;

	if (numRows == 2)
		return pTriangle;

	for (i = 2; i < numRows; i++) {
		pTriangle[i] = malloc(sizeof(**pTriangle) * (i + 1));
		pTriangle[i][0] = 1;
		for (j = 1; j < i; j++)
			pTriangle[i][j] = pTriangle[i - 1][j] + pTriangle[i - 1][j - 1];
		pTriangle[i][i] = 1;
		(*columnSizes)[i] = i + 1;
	}

	return pTriangle;
}


