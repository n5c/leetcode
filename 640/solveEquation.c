#include <leetcode.h>

char* solveEquation(char* equation)
{
	int i, a, b, minus, tmp, isX;
	char c, s[100];

	i = 0;
	a = 0;
	b = 0;
	minus = 1;
	tmp = 0;
	isX = 0;
	while ((c = equation[i])) {
		if (c >= '0' && c <= '9') {
			tmp *= 10;
			tmp += c - '0';

		} else {
			if (c == 'x') {
				isX = 1;
				if (!tmp) {
					tmp = 1;
					if (i && equation[i - 1] == '0')
						tmp = 0;

				}

			}
			if (isX)
				a += minus * tmp;
			else
				b += minus * tmp;
			minus = 1;
			tmp = 0;
			isX = 0;
			if (c == '-')
				minus = -1;
			if (c == '=')
				break;

		}
		i++;

	}

	while ((c = equation[i])) {
		if (c >= '0' && c <= '9') {
			tmp *= 10;
			tmp += c - '0';

		} else {
			if (c == 'x') {
				isX = 1;
				if (!tmp) {
					tmp = 1;
					if (i && equation[i - 1] == '0')
						tmp = 0;

				}

			}
			if (isX)
				a -= minus * tmp;
			else
				b -= minus * tmp;
			minus = 1;
			tmp = 0;
			isX = 0;
			if (c == '-')
				minus = -1;

		}
		i++;

	}

	if (tmp)
		b -= minus * tmp;
	b = -b;

	if (!a) {
		if (b)
			return strdup("No solution");
		else
			return strdup("Infinite solutions");

	}

	b = b/a;
	snprintf(s, 100, "x=%d", b);
	return strdup(s);

}

void tc_0(void)
{
	char *s = solveEquation("x+5-3+x=6+x-2");
	printf("x=2\n%s\n\n", s);
	free(s);

	s = solveEquation("x=x");
	printf("Infinite solutions\n%s\n\n", s);
	free(s);

	s = solveEquation("2x=x");
	printf("x=0\n%s\n\n", s);
	free(s);

	s = solveEquation("2x+3x-6x=x+2");
	printf("x=-1\n%s\n\n", s);
	free(s);

	s = solveEquation("x=x+2");
	printf("No solution\n%s\n\n", s);
	free(s);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

