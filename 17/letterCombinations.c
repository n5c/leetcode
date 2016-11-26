#include <leetcode.h>

/**
 *  * Return an array of size *returnSize.
 *   * Note: The returned array must be malloced, assume caller calls free().
 *    */
char** letterCombinations(char* digits, int* returnSize)
{
	char *letters[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	int lens[] = {0,0,3,3,3,3,3,4,3,4};
	char **combs;
	int i, j, c, len, *count;

	*returnSize = 1;
	for (i = 0; digits[i]; i++)
		*returnSize *= lens[digits[i] - '0'];

	if (!i || !(*returnSize)) {
		*returnSize = 0;
		combs = malloc(sizeof(*combs) * 1);
		return combs;
	}

	len = i;
	combs = malloc(sizeof(*combs) * *returnSize);
	count = malloc(sizeof(*count) * len);
	memset(count, 0, sizeof(count));

	i = 0;
	for (i = 0; i < *returnSize; i++) {
		combs[i] = malloc(sizeof(**combs) * (len + 1));
		combs[i][len] = 0;
		for (j = len - 1, c = 1; j >= 0; j--) {
			count[j] += c;
			c = count[j] / lens[digits[j] - '0'];
			count[j] %= lens[digits[j] - '0'];
			combs[i][j] = letters[digits[j] - '0'][count[j]];
		}
	}

	free(count);

	return combs;
}

void print(char **combs, int size)
{
	for (int i = 0; i < size; i++) {
		printf("%s", combs[i]);
		if (i + 1 != size)
			printf(",");
	}
	printf("\n\n");
}

void tc_0(void)
{
	char **combs, digits[] = "122";
	int size;
	printf("[]\n");
	combs = letterCombinations(digits, &size);
	print(combs, size);
	for (int i = 0; i < size; i++)
		free(combs[i]);
	free(combs);
}

void tc_1(void)
{
	char **combs, digits[] = "202";
	int size;
	printf("[]\n");
	combs = letterCombinations(digits, &size);
	print(combs, size);
	for (int i = 0; i < size; i++)
		free(combs[i]);
	free(combs);
}

void tc_2(void)
{
	char **combs, digits[] = "23";
	int size;
	printf("ae,af,bd,be,bf,cd,ce,cf,ad\n");
	combs = letterCombinations(digits, &size);
	print(combs, size);
	for (int i = 0; i < size; i++)
		free(combs[i]);
	free(combs);
}

void tc_3(void)
{
	char **combs, digits[] = "22";
	int size;
	printf("ab,ac,ba,bb,bc,ca,cb,cc,aa\n");
	combs = letterCombinations(digits, &size);
	print(combs, size);
	for (int i = 0; i < size; i++)
		free(combs[i]);
	free(combs);
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	tc_2();
	tc_3();
	return 0;
}

