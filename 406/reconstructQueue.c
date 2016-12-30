#include <leetcode.h>

int** reconstructQueue(int** people, int peopleRowSize, int peopleColSize, int** columnSizes, int* returnSize)
{
	int i, j, skip;
	int **returnArr, *tmp;

	*returnSize = peopleRowSize;
	returnArr = malloc(sizeof(*returnArr) * (*returnSize));

	printf("%d, %d\n", peopleRowSize, peopleColSize);

	*columnSizes = malloc(sizeof(**columnSizes) * (*returnSize));
	for (i = 0; i < *returnSize; i++) {
		(*columnSizes)[i] = peopleColSize;
		returnArr[i] = malloc(sizeof(**returnArr) * peopleColSize);
		returnArr[i][0] = -1;
	}

	int cmp(const void *a, const void *b) {
		const int **ia = (const int **)a;
		const int **ib = (const int **)b;
		int v = (*ia)[0] - (*ib)[0];
		if (v)
			return v;
		return (*ia)[1] - (*ib)[1];
	}

	qsort(people, peopleRowSize, sizeof(*people), cmp);

	for (i = 0; i < peopleRowSize; i++) {
		for (j = 0, skip = 0; j < peopleRowSize; j++) {
			if (returnArr[j][0] != -1) {
				if (returnArr[j][0] >= people[i][0])
					skip++;
				continue;
			}
			if (people[i][1] == skip)
				break;
			skip++;
		}
		returnArr[j][0] = people[i][0];
		returnArr[j][1] = people[i][1];
	}

	return returnArr;
}

void print(int **arr, int *columnSizes, int size)
{
	for (int i = 0; i < size; i++) {
		printf("[%d", arr[i][0]);
		for (int j = 1; j < columnSizes[i]; j++)
			printf(",%d", arr[i][j]);
		printf("] ");
	}
	printf("\n\n");
}

void freeArr(int **arr, int *returnSize, int size)
{
	for (int i = 0; i < size; i++)
		free(arr[i]);
	free(arr);
	free(returnSize);
}

void tc_0(void)
{
	int _people[][2] = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
	int *people[] = {
		_people[0], _people[1], _people[2],
		_people[3], _people[4], _people[5]
	};
	int peopleRowSize = sizeof(people)/sizeof(*people);
	int peopleColSize = (sizeof(people)/peopleRowSize)/sizeof(**people);
	int **returnArr, returnSize, *columnSizes;

	returnArr = reconstructQueue(people, peopleRowSize, peopleColSize,
				     &columnSizes, &returnSize);

	print(returnArr, columnSizes, returnSize);
	freeArr(returnArr, columnSizes, returnSize);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

