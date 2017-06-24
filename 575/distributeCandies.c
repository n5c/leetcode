#include <leetcode.h>

int cmp (const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int distributeCandies(int* candies, int candiesSize)
{
	int kinds;

	if (candiesSize == 0)
		return 0;

	qsort(candies, candiesSize, sizeof(int), cmp);

	kinds = 1;
	for (int i = 1; i < candiesSize; i++) {
		if (candies[i] != candies[i - 1]) {
			kinds++;
			if (kinds >= (candiesSize >> 1)) {
				kinds = (candiesSize >> 1);
				break;
			}
		}
	}

	return kinds;
}

void tc_0(void)
{
	int candies[] = {1,1,2,2,3,3};
	int candiesSize = sizeof(candies)/sizeof(*candies);
	printf("%d\n", distributeCandies(candies, candiesSize));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

