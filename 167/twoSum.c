#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
	int i, j, k;
	int *returnNumbers;

	i = 0;
	j = numbersSize - 1;
	while (i < j) {
		k = target - numbers[j];
		if (numbers[i] == k)
			break;
		if (numbers[i] < k)
			i++;
		else
			j--;
	}

	returnNumbers = malloc(sizeof(*returnNumbers) * 2);
	*returnSize = 2;

	returnNumbers[0] = i + 1;
	returnNumbers[1] = j + 1;

	return returnNumbers;
}
