#include <stdio.h>
#include <limits.h>

int myAtoi(char* str)
{
	const char INT_MAX_STR[] = "2147483647";
	int i, j, k, neg = 0;

	/* remove whitespace */
	while (*str == ' ') str++;

	if (!(*str))
		return 0;

	/* take  */
	if (*str == '-') {
		neg++;
		str++;
	} else if (*str == '+') {
		str++;
	}

	i = 0;
	while (i < 11) {
		if ((str[i] < '0') || (str[i] > '9'))
			break;
		i++;
	}

	if (!i)
		return 0;

	if (i > 10)
		return ((neg) ? INT_MIN : INT_MAX);

	if (i == 10) {
		for (j = 0; j < 9; j++) {
			if (str[j] > INT_MAX_STR[j])
				return ((neg) ? INT_MIN : INT_MAX);
			if (str[j] < INT_MAX_STR[j])
				break;
		}
		if (j == 9) {
			if (str[j] > INT_MAX_STR[j])
				return ((neg) ? INT_MIN : INT_MAX);
		}
	}

	for (j = 0, k = 0; j < i; j++) {
		k *= 10;
		k += str[j] - '0';
	}

	if (neg)
		k = -k;

	return k;
}

