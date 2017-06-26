#include <leetcode.h>

int* constructRectangle(int area, int* returnSize)
{
	int i, j;
	int *side;

	*returnSize = 2;
	side = malloc(sizeof(*side) * 2);

	if (!area) {
		side[0] = 0;
		side[1] = 0;
	} else {
		for (i = (int)sqrt((double)area); i >= 1; i--) {
			j = area % i;
			if (!j)
				break;
		}
		side[0] = area / i;
		side[1] = i;
	}

	return side;
}

void tc_0(void)
{
	int returnSize;
	int *rec = constructRectangle(1, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		if (i)
			printf(" ");
		printf("%d", rec[i]);
	}
	printf("\n");
	free(rec);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

