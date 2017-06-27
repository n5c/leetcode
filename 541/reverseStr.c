#include <leetcode.h>

char* reverseStr(char* s, int k)
{
	int i, j, l, n;
	const int k2 = k << 1;

	for (n = 0; s[n]; n++);

	for (l = 0; l < n; l += k2) {
		i = l;
		j = l + k - 1;
		if (j >= n)
			j = n - 1;
		while (i < j) {
			int tmp = s[i];
			s[i] = s[j];
			s[j] = tmp;
			i++;
			j--;
		}
	}

	return s;
}

void tc_0(void)
{
	char s[] = "abcdefg";
	reverseStr(s, 2);
	printf("bacdefg\n%s\n", s);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

