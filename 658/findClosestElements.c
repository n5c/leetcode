#include <leetcode.h>

int* findClosestElements(int* arr, int arrSize, int k, int x,
		int* returnSize)
{
	int i, j, m, n, mid, count, *ce;

	*returnSize = k;
	ce = malloc(sizeof(*ce) * k);

	i = 0;
	j = arrSize - 1;
	while (i <= j) {
		mid = ((i + j) / 2);
		if (x > arr[mid])
			i = mid + 1;
		else if (x < arr[mid])
			j = mid - 1;
		else
			break;
	}

	i = mid;
	m = x - arr[mid];
	if (m < 0)
		m = -m;
	if (mid) {
		n = x - arr[mid - 1];
		if (n < 0)
			n = -n;
		if (n < m) {
			i = mid - 1;
			m = n;
		}
	}
	if (mid + 1 < arrSize) {
		n = x - arr[mid + 1];
		if (n < 0)
			n = -n;
		if (n < m)
			i = mid + 1;
	}

	mid = i;

	count = 1;
	j = mid;
	while (count < k) {
		if (i - 1 < 0)
			break;
		m = x - arr[i - 1];
		if (m < 0)
			m = -m;
		if (j + 1 >= arrSize)
			break;
		n = x - arr[j + 1];
		if (n < 0)
			n = -n;
		if (m <= n)
			i--;
		else
			j++;
		count++;
	}

	while ((i - 1 >= 0) && count < k) {
		i--;
		count++;
	}
	while ((j + 1 < arrSize) && count < k) {
		j++;
		count++;
	}

	for (m = 0, n = i; m < k; m++, n++)
		ce[m] = arr[n];

	return ce;

}

void tc_0(void)
{
	int arr[] = {1,5,21,22,24,25};
	int arrSize = sizeof(arr)/sizeof(*arr);
	int returnSize;
	int *elements = findClosestElements(arr, arrSize, 3, 19,
				&returnSize);
	printf("21,22,24\n");
	for (int i = 0; i < returnSize; i++) {
		if (i)
			printf(",");
		printf("%d", elements[i]);
	}
	printf("\n\n");
	free(elements);
}

void tc_1(void)
{
	int arr[] = {1,5,16,19,20,26,27};
	int arrSize = sizeof(arr)/sizeof(*arr);
	int returnSize;
	int *elements = findClosestElements(arr, arrSize, 3, 21,
				&returnSize);
	printf("16,19,20\n");
	for (int i = 0; i < returnSize; i++) {
		if (i)
			printf(",");
		printf("%d", elements[i]);
	}
	printf("\n\n");
	free(elements);
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	return 0;
}

