#include <leetcode.h>

char* countAndSay(int n)
{
	int i, j, k, l, m, o, casSize, _casSize;
	char *cas, *_cas;

	casSize = 2;
	cas = malloc(sizeof(*cas) * casSize);
	cas[0] = '1';
	cas[1] = 0;
	_casSize = 2;
	_cas = malloc(sizeof(*cas) * casSize);

	for (i = 2; i <= n; i++) {
		for (j = 0, k = 1, l = 1, o = 0; cas[j]; j++) {
			if (cas[j] == cas[j + 1]) {
				k++;
				continue;
			}
			m = k;
			for (; m; m /= 10, l++);
			l++;
			if (l > _casSize) {
				_casSize = l;
				_cas = realloc(_cas, sizeof(*_cas) * _casSize);
			}

			snprintf(&_cas[o], l, "%d%c", k, cas[j]);
			o = l - 1;
			k = 1;
		}

		if (_casSize > casSize) {
			casSize = _casSize;
			cas = realloc(cas, sizeof(*cas) * casSize);
		}
		strcpy(cas, _cas);
	}

	free(_cas);

	return cas;
}

void tc_0(void)
{
	int n;
	char *cas;

	n = 2;
	cas = countAndSay(n);
	printf("%s\n", cas);
	free(cas);

	n = 3;
	cas = countAndSay(n);
	printf("%s\n", cas);
	free(cas);

	n = 4;
	cas = countAndSay(n);
	printf("%s\n", cas);
	free(cas);

	n = 5;
	cas = countAndSay(n);
	printf("%s\n", cas);
	free(cas);

	n = 6;
	cas = countAndSay(n);
	printf("%s\n", cas);
	free(cas);

	n = 7;
	cas = countAndSay(n);
	printf("%s\n", cas);
	free(cas);

	n = 10;
	cas = countAndSay(n);
	printf("%s\n", cas);
	free(cas);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

