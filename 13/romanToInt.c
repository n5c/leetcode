#include <stdio.h>
#include <string.h>

char romanDigits[][3] =
{
	{'I', 'V', 'X'},
	{'X', 'L', 'C'},
	{'C', 'D', 'M'},
	{'M', 'M', 'M'}
};

int level[] = {1, 10, 100, 1000};

int romanToInt(char* s)
{
	int num, tmp, len, d;

	num = 0;
	len = strlen(s) - 1;
	for (d = 0; d < 4; d++) {
		tmp = 0;
		while (len >= 0) {
			if (s[len] == romanDigits[d][0]) {
				tmp = tmp + 1;

				if (s[len] == 'M') {
					len = len - 1;
					continue;
				}

				if ((s[len + 1] == romanDigits[d][1]) ||
						(s[len + 1] == romanDigits[d][2])) {
					tmp = tmp - 2;
					len = len - 1;
					break;
				} else if (len &&
						(s[len - 1] != romanDigits[d][0]) &&
						(s[len - 1] != romanDigits[d][1])) {
					len = len - 1;
					break;
				}
			} else if (s[len] == romanDigits[d][1]) {
				tmp = tmp + 5;
				if (len && s[len - 1] != romanDigits[d][0]) {
					len = len - 1;
					break;
				}
			} else if (s[len] == romanDigits[d][2]) {
				tmp = tmp + 10;
			} else {
				break;
			}

			len = len - 1;
		}

		num = num + (tmp * level[d]);
	}

	return num;
}

