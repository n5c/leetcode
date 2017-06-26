#include <leetcode.h>

char* convertToBase7(int num)
{
	int i, j, k, minus;
	char *str;

	str = calloc(sizeof(*str), 20);

	k = 0;
	i = num;
	minus = 0;
	if (i < 0) {
		i = -i;
		minus = 1;
		str[0] = '-';
		k = 1;
	}

	do {
		j = i % 7;
		i /= 7;
		str[k++] = '0' + j;
	} while(i);

	for (i = minus, j = k - 1; i < j; i++, j--) {
		k = str[i];
		str[i] = str[j];
		str[j] = k;
	}

	return str;
}

void tc_0(void)
{
	char *s = convertToBase7(100);
	printf("202: %s\n", s);
	free(s);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

