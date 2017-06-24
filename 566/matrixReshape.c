#include <leetcode.h>

int** matrixReshape(int** nums, int numsRowSize, int numsColSize, int r, int c, int** columnSizes, int* returnSize)
{
	int **matrix;

	if (numsRowSize * numsColSize != r * c) {
		*returnSize = numsRowSize;
		*columnSizes = malloc(sizeof(**columnSizes) * numsRowSize);
		matrix = malloc(sizeof(*matrix) * numsRowSize);
		for (int i = 0; i < numsRowSize; i++) {
			(*columnSizes)[i] = numsColSize;
			matrix[i] = malloc(sizeof(**matrix) * numsColSize);
			for (int j = 0; j < numsColSize; j++)
				matrix[i][j] = nums[i][j];
		}

		return matrix;
	}

	int count = 0;
	*returnSize = r;
	*columnSizes = malloc(sizeof(**columnSizes) * r);
	matrix = malloc(sizeof(*matrix) * r);
	for (int i = 0; i < r; i++) {
		(*columnSizes)[i] = c;
		matrix[i] = malloc(sizeof(**matrix) * c);
		for (int j = 0; j < c; j++, count++)
			matrix[i][j] = nums[count / numsColSize][count % numsColSize];
	}

	return matrix;
}

void tc_0(void)
{
	// TODO...
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

