#include <leetcode.h>

int* findAnagrams(char* s, char* p, int* returnSize)
{
	int i, j, k, l, m, n, o, sum, psum;
	int *loc;

	for (k = 0, psum = 0; p[k]; k++)
		psum += p[k];

	*returnSize = 1;
	loc = malloc(sizeof(*loc) * *returnSize);

	for (j = 0, sum = 0; j < k && s[j]; j++)
		sum += s[j];

	o = 0;
	i = 0;
	j--;
	while (s[j]) {
		if (sum == psum) {
			for (l = 0; l < k; l++) {
				if (s[i] != p[l])
					continue;
				for (m = i, n = l; m <= j && s[m] == p[n]; m++, n = ((n + 1 < k) ? n + 1: 0));
				if (m > j) {
					loc[o++] = i;
					if (o >= *returnSize) {
						int *tmp = malloc(sizeof(*tmp) * (*returnSize << 1));
						memcpy(tmp, loc, sizeof(*tmp) * *returnSize);
						free(loc);
						loc = tmp;
						*returnSize <<= 1;
					}
					break;
				}

				for (m = i, n = l; m < j && s[m] == p[n]; m++, n = ((n - 1 >= 0) ? n - 1: k - 1));
				if (m >= j) {
					loc[o++] = i;
					if (o >= *returnSize) {
						int *tmp = malloc(sizeof(*tmp) * (*returnSize << 1));
						memcpy(tmp, loc, sizeof(*tmp) * *returnSize);
						free(loc);
						loc = tmp;
						*returnSize <<= 1;
					}
					break;
				}
			}
		}

		sum -= s[i++];
		sum += s[++j];
	}

	*returnSize = o;
	return loc;
}

void tc_1(void)
{
	char s[] = "abab";
	char p[] = "ab";
	int returnSize;
	int *a = findAnagrams(s, p, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		if (i)
			printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
	free(a);
}

void tc_0(void)
{
	char s[] = "cbaebabacd";
	char p[] = "abc";
	int returnSize;
	int *a = findAnagrams(s, p, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		if (i)
			printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
	free(a);
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	return 0;
}

