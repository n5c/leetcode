#include <leetcode.h>

static int cmp(const void *a, const void *b)
{
	int *ia = *((int **)a);
	int *ib = *((int **)b);
	int c = ia[0] - ib[0];
	if (c)
		return c;
	return ia[1] - ib[1];

}

int findLongestChain(int** pairs, int pairsRowSize, int pairsColSize)
{
	int i, j, max, chk[pairsRowSize];
	qsort(pairs, pairsRowSize, sizeof(*pairs), cmp);
	for (i = 0; i < pairsRowSize; i++)
		chk[i] = 1;
	for (i = 0, max = 1; i < pairsRowSize; i++) {
		for (j = i + 1; j < pairsRowSize; j++) {
			if (pairs[j][0] > pairs[i][1])
				break;

		}
		for (; j < pairsRowSize; j++) {
			if (chk[i] + 1 > chk[j]) {
				chk[j] = chk[i] + 1;
				if (chk[j] > max)
					max = chk[j];

			}

		}

	}
	return max;

}

void tc_0(void)
{
	int _pairs[][8] = {
		{7,9},{4,5},{7,9},{-7,-1},
		{0,10},{3,10},{3,6},{2,3}
	};
	int *pairs[] = {
		_pairs[0], _pairs[1], _pairs[2], _pairs[3],
		_pairs[4], _pairs[5], _pairs[6], _pairs[7]
	};
	int pairsRowSize = 8;
	int pairsColSize = 2;
	printf("4\n%d\n\n", findLongestChain(pairs, pairsRowSize,
				pairsColSize));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

