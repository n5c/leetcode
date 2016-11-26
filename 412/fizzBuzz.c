#include <stdio.h>
#include <stdlib.h>

/**
 *  * Return an array of size *returnSize.
 *   * Note: The returned array must be malloced, assume caller calls free().
 *    */
char** fizzBuzz(int n, int* returnSize) {
	char **array;
	int i, j, tmp;

	array = malloc(sizeof(*array) * n);
	for (i = 0; i < n; i++) {
		for (j = 0, tmp = (i + 1); tmp; j++, tmp/=10);
		array[i] = malloc(sizeof(char) * (j + 1));
		array[i][j] = 0;
		for (j--, tmp = (i + 1); tmp; j--, tmp/=10)
			array[i][j] = ((tmp % 10) + '0');
	}

	for (i = (3 - 1); i < n; i+=3) {
		free(array[i]);
		array[i] = malloc(sizeof(char) * 5);
		array[i][0] = 'F';
		array[i][1] = 'i';
		array[i][2] = 'z';
		array[i][3] = 'z';
		array[i][4] = 0;
	}

	for (i = (5 - 1); i < n; i+=5) {
		if (array[i][0] != 'F') {
			free(array[i]);
			array[i] = malloc(sizeof(char) * 5);
			array[i][0] = 'B';
			array[i][1] = 'u';
			array[i][2] = 'z';
			array[i][3] = 'z';
			array[i][4] = 0;
		} else {
			free(array[i]);
			array[i] = malloc(sizeof(char) * 9);
			array[i][0] = 'F';
			array[i][1] = 'i';
			array[i][2] = 'z';
			array[i][3] = 'z';
			array[i][4] = 'B';
			array[i][5] = 'u';
			array[i][6] = 'z';
			array[i][7] = 'z';
			array[i][8] = 0;
		}
	}

	*returnSize = n;

	return array;
}

void print(char **array, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%s\n", array[i]);
}

void free_fizzbuzz(char **array, int size)
{
	int i;
	for (i = 0; i < size; i++)
		free(array[i]);
	free(array);
}

void test_case_0(void)
{
	char **array;
	int size;
	array = fizzBuzz(1, &size);
	print(array, size);
	free_fizzbuzz(array, size);
}

void test_case_1(void)
{
	char **array;
	int size;
	array = fizzBuzz(15, &size);
	print(array, size);
	free_fizzbuzz(array, size);
}

int main(int argc, char *argv[])
{
	/* test_case_0(); */
	test_case_1();
	return 0;
}
