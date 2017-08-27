#include <leetcode.h>

int** imageSmoother(int** M, int MRowSize, int MColSize,
		int** columnSizes, int* returnSize) {
	int i, j, sum, div, **image;

	*returnSize = MRowSize;
	*columnSizes = malloc(sizeof(**columnSizes) * MRowSize);
	image = malloc(sizeof(*image) * MRowSize);
	for (i = 0; i < MRowSize; i++) {
		image[i] = malloc(sizeof(**image) * MColSize);
		(*columnSizes)[i] = MColSize;
	}

	sum = M[0][0];
	div = 1;
	if (MRowSize > 1) {
		sum += M[1][0];
		div++;
	}
	for (i = 0, j = 0; i < MRowSize; i++) {
		if (!(i & 0x1)) {
			if (j < 0) {
				j = 0;
				if (i - 2 >= 0) {
					sum -= M[i - 2][j];
					div--;
					if (j + 1 < MColSize) {
						sum -= M[i - 2][j + 1];
						div--;
					}
				}
				if (i + 1 < MRowSize) {
					sum += M[i + 1][j];
					div++;
					if (j + 1 < MColSize) {
						sum += M[i + 1][j + 1];
						div++;
					}
				}
				image[i][j] = sum / div;
				j++;
			}
			for (; j < MColSize; j++) {
				if (j - 2 >= 0) {
					if (i - 1 >= 0) {
						sum -= M[i - 1][j - 2];
						div--;
					}
					sum -= M[i][j - 2];
					div--;
					if (i + 1 < MRowSize) {
						sum -= M[i + 1][j - 2];
						div--;
					}
				}
				if (j + 1 < MColSize) {
					if (i - 1 >= 0) {
						sum += M[i - 1][j + 1];
						div++;
					}
					sum += M[i][j + 1];
					div++;
					if (i + 1 < MRowSize) {
						sum += M[i + 1][j + 1];
						div++;
					}
				}
				image[i][j] = sum / div;
			}
		} else {
			if (j >= MColSize) {
				j = MColSize - 1;
				if (i - 2 >= 0) {
					if (j - 1 >= 0) {
						sum -= M[i - 2][j - 1];
						div--;
					}
					sum -= M[i - 2][j];
					div--;
				}
				if (i + 1 < MRowSize) {
					if (j - 1 >= 0) {
						sum += M[i + 1][j - 1];
						div++;
					}
					sum += M[i + 1][j];
					div++;
				}
				image[i][j] = sum / div;
				j--;
			}
			for (; j >= 0; j--) {
				if (j + 2 < MColSize) {
					if (i - 1 >= 0) {
						sum -= M[i - 1][j + 2];
						div--;
					}
					sum -= M[i][j + 2];
					div--;
					if (i + 1 < MRowSize) {
						sum -= M[i + 1][j + 2];
						div--;
					}
				}
				if (j - 1 >= 0) {
					if (i - 1 >= 0) {
						sum += M[i - 1][j - 1];
						div++;
					}
					sum += M[i][j - 1];
					div++;
					if (i + 1 < MRowSize) {
						sum += M[i + 1][j - 1];
						div++;
					}
				}
				image[i][j] = sum / div;
			}
		}
	}

	return image;
}

void freePrint(int **images, int *columnSizes, int returnSize)
{
	int i, j;
	for (i = 0; i < returnSize; i++) {
		if (i)
			printf(",\n");
		printf("{");
		for (j = 0; j < columnSizes[i]; j++) {
			if (j)
				printf(",");
			printf("%d", images[i][j]);
		}
		printf("}");
		free(images[i]);
	}
	printf("\n");
	free(images);
	free(columnSizes);
}
void tc_0(void)
{
	int _M[][3] = {{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16}};
	int *M[] = {_M[0], _M[1], _M[2], _M[3], _M[4]};
	int MRowSize = 5;
	int MColSize = 3;
	int *columnSizes;
	int returnSize;
	int **images = imageSmoother(M, MRowSize, MColSize,
			&columnSizes, &returnSize);
	freePrint(images, columnSizes, returnSize);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

