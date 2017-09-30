#include <leetcode.h>

static int compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

static int *__candidates;
static int __candidatesSize;
static int **__columnSizes;
static int *__returnSize;
static int **combs;
static int combsSize;
static int combsIndex;
static int *set;
static int setSize;
static void backtrack(int start, int target)
{
	for (int i = start; i < __candidatesSize; ++i) {
		while (i > start && i < __candidatesSize && __candidates[i] == __candidates[i - 1]) i++;
		if (__candidates[i] > target)
			break;
		++set[setSize - 1];
		++set[i];
		if (__candidates[i] == target) {
			if (combsIndex >= combsSize) {
				combsSize = combsSize ? (combsSize << 1) : 1;
				combs = realloc(combs, sizeof(*combs) * combsSize);
				*__columnSizes = realloc(*__columnSizes, sizeof(**__columnSizes) * combsSize);
			}
			combs[combsIndex] = malloc(sizeof(**combs) * set[setSize - 1]);
			(*__columnSizes)[combsIndex] = set[setSize - 1];
			int l = 0;
			for (int j = 0; j < setSize - 1; ++j) {
				if (!set[j])
					continue;
				for (int k = 0; k < set[j]; ++k)
					combs[combsIndex][l++] = __candidates[j];
			}
			++combsIndex;
			--set[setSize - 1];
			--set[i];
			break;

		}
		backtrack(i + 1, target - __candidates[i]);
		--set[setSize - 1];
		--set[i];
	}
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize)
{
	qsort(candidates, candidatesSize, sizeof(*candidates), compare);

	__candidates = candidates;
	__candidatesSize = candidatesSize;
	__columnSizes = columnSizes;
	*__columnSizes = NULL;
	__returnSize = returnSize;
	*__returnSize = 0;
	combs = NULL;
	combsSize = 0;
	combsIndex = 0;
	if (candidatesSize + 1 > setSize) {
		setSize = candidatesSize + 1;
		set = realloc(set, sizeof(*set) * setSize);
	}
	memset(set, 0, sizeof(*set) * setSize);
	backtrack(0, target);
	*returnSize = combsIndex;
	return combs;

}

void tc_0(void)
{
	int candidates[] = {10,1,2,7,6,1,5};
	int candidatesSize = sizeof(candidates) / sizeof(*candidates);
	int *columnSizes, returnSize;
	int **combs = combinationSum2(candidates, candidatesSize, 8,
			&columnSizes, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		for (int j = 0; j < columnSizes[i]; j++) {
			if (j)
				printf(",");
			printf("%d", combs[i][j]);
		}
		printf("\n");
		free(combs[i]);
	}
	free(combs);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

