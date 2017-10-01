#include <leetcode.h>

int repeatedStringMatch(char* A, char* B)
{
	int i = 0, j, k, count = 1;
	while (A[i]) {
		j = 0;
		while (A[i] && (A[i] != B[j]))
			i++;
		if (!A[i])
			return -1;
		k = i;
		while (A[k] && B[j] && (A[k] == B[j])) {
			k++;
			j++;
		}
		if (!B[j])
			return 1;
		if (!A[k]) {
			i = k;
			break;
		}
		if (A[i])
			i++;
	}
	while (B[j]) {
		if (!A[i]) {
			i = 0;
			count++;
		}
		if (A[i] != B[j])
			return -1;
		i++;
		j++;
	}
	return count;
}

void tc_0(void)
{
	char A[] = "abcd";
	char B[] = "cdabcdab";
	printf("3\n%d\n\n", repeatedStringMatch(A,B));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

