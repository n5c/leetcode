#include <leetcode.h>

int* constructArray(int n, int k, int* returnSize)
{
	int i, *a;
	*returnSize = n;
	a = malloc(sizeof(*a) * n);
	a[0] = 1;
	for (i = 1; k; i++, k--) {
		if (i & 1)
			a[i] = a[i - 1] + k;
		else
			a[i] = a[i - 1] - k;
	}
	for (; i < n; i++)
		a[i] = i + 1;
	return a;
}


void tc_0(void)
{
	int returnSize;
	int *a = constructArray(10, 6, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		if (i)
			printf(",");
		printf("%d", a[i]);
	}
	printf("\n");
	free(a);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

