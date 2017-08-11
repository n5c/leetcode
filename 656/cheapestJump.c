#include <leetcode.h>

int* cheapestJump(int* A, int ASize, int B, int* returnSize)
{
	int i, j, k, l, m, n, cost, places, chk[ASize][3], chklex[2][ASize], *path;

	/* chk[0 .. ASize - 1][prevPlace, cost, places] */
	for (i = 0; i < ASize; i++) {
		chk[i][0] = -1;
		chk[i][1] = 0;
		chk[i][2] = 0;
	}
	chk[0][1] = A[0];
	chk[0][2] = 1;

	for (i = 0; i < ASize; i++) {
		k = i + B + 1;
		k = (k < ASize ? k : ASize);
		if (!chk[i][2])
			continue;

		for (j = i + 1; j < k; j++) {
			if (A[j] <= -1)
				continue;

			cost = A[j] + chk[i][1];
			places = chk[i][2] + 1;
			if (chk[j][0] == -1 || cost < chk[j][1]) {
				chk[j][0] = i;
				chk[j][1] = cost;
				chk[j][2] = places;
				continue;
			}

			if (cost > chk[j][1])
				continue;

			for (m = chk[j][2] - 1, l = j; m >= 0; l = chk[l][0], m--)
				chklex[0][m] = l;
			m = chk[i][2];
			chklex[1][m--] = j;
			for (l = i; m >= 0; l = chk[l][0], m--)
				chklex[1][m] = l;

			if ((chk[i][2] + 1) <= chk[j][2]) {
				m = chk[i][2] + 1;
				n = 1;
			} else {
				m = chk[j][2];
				n = -1;
			}

			for (l = 0; l < m; l++) {
				if (chklex[0][l] == chklex[1][l])
					continue;
				n = chklex[0][l] - chklex[1][l];
				break;
			}

			if (n <= 0)
				continue;

			chk[j][0] = i;
			chk[j][1] = cost;
			chk[j][2] = places;
		}
	}

	if (!chk[ASize - 1][2]) {
		*returnSize = 0;
		return NULL;
	}

	*returnSize = chk[ASize - 1][2];
	path = malloc(sizeof(*path) * *returnSize);
	for (i = *returnSize - 1, j = ASize - 1; i >= 0; i--, j = chk[j][0])
		path[i] = j + 1;

	return path;
}

void tc_0(void)
{
	int A[] = {1,2,4,-1,2};
	int ASize = sizeof(A)/sizeof(*A);
	int B = 2;
	int returnSize;
	int *path = cheapestJump(A, ASize, B, &returnSize);
	printf("[1,3,5]\n[");
	for (int i = 0; i < returnSize; i++) {
		if (i)
			printf(",");
		printf("%d", path[i]);
	}
	printf("]\n\n");

	if (path)
		free(path);
}

void tc_1(void)
{
	int A[] = {1,2,4,-1,2};
	int ASize = sizeof(A)/sizeof(*A);
	int B = 1;
	int returnSize;
	int *path = cheapestJump(A, ASize, B, &returnSize);
	printf("[]\n[");
	for (int i = 0; i < returnSize; i++) {
		if (i)
			printf(",");
		printf("%d", path[i]);
	}
	printf("]\n\n");

	if (path)
		free(path);
}
void tc_2(void)
{
	int A[] = {1,2,5,4,2};
	int ASize = sizeof(A)/sizeof(*A);
	int B = 2;
	int returnSize;
	int *path = cheapestJump(A, ASize, B, &returnSize);
	printf("[1,3,5]\n[");
	for (int i = 0; i < returnSize; i++) {
		if (i)
			printf(",");
		printf("%d", path[i]);
	}
	printf("]\n\n");

	if (path)
		free(path);
}
void tc_3(void)
{
	int A[] = {0,0,0,0,0,0};
	int ASize = sizeof(A)/sizeof(*A);
	int B = 3;
	int returnSize;
	int *path = cheapestJump(A, ASize, B, &returnSize);
	printf("[1,2,3,4,5,6]\n[");
	for (int i = 0; i < returnSize; i++) {
		if (i)
			printf(",");
		printf("%d", path[i]);
	}
	printf("]\n\n");

	if (path)
		free(path);
}
void tc_4(void)
{
	int A[] = {1};
	int ASize = sizeof(A)/sizeof(*A);
	int B = 1;
	int returnSize;
	int *path = cheapestJump(A, ASize, B, &returnSize);
	printf("[1]\n[");
	for (int i = 0; i < returnSize; i++) {
		if (i)
			printf(",");
		printf("%d", path[i]);
	}
	printf("]\n\n");

	if (path)
		free(path);
}
int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	tc_2();
	tc_3();
	tc_4();
	return 0;
}

