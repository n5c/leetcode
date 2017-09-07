#include <leetcode.h>

char** generateParenthesis(int n, int* returnSize)
{
	int i, j, k, __par[n];
	char **par;

	if (!n) {
		*returnSize = 0;
		return NULL;
	}

	if (n == 1) {
		*returnSize = 1;
		par = malloc(sizeof(*par) * 1);
		par[0] = strdup("()");
		return par;
	}

	for (i = 0; i < n; i++)
		__par[i] = i;
	*returnSize = 0;
	while (1) {
		(*returnSize)++;
		for (j = n - 1; j; j--) {
			if (__par[j] < (j << 1))
				break;
		}
		if (!j)
			break;
		__par[j++]++;
		for (; j < n; j++)
			__par[j] = __par[j - 1] + 1;
	}
	par = malloc(sizeof(*par) * (*returnSize));

	for (i = 0; i < n; i++)
		__par[i] = i;
	for (i = 0; i < *returnSize; i++) {
		par[i] = malloc(sizeof(**par) * ((n << 1) + 1));
		par[i][(n << 1)] = 0;

		for (j = (n << 1) - 1, k = n - 1; j >= 0; j--) {
			if (j == __par[k]) {
				par[i][j] = '(';
				k--;
			} else {
				par[i][j] = ')';
			}
		}

		for (j = n - 1; j; j--) {
			if (__par[j] < (j << 1))
				break;
		}

		__par[j++]++;

		for (; j < n; j++)
			__par[j] = __par[j - 1] + 1;
	}

	return par;
}

void tc_0(void)
{
	int i, returnSize;
	char **par = generateParenthesis(3, &returnSize);
	for (i = 0; i < returnSize; i++) {
		if (i)
			printf(",");
		printf("%s", par[i]);
		free(par[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

