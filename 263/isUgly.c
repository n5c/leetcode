#include <stdio.h>

#define bool int
#define true 1
#define false 0

bool isUgly(int num) {
	/* static char *chk = NULL;
	static int chksz = sqrt(INT_MAX);
	int i, j, k;
	if (!chk) {
		chk = calloc(sizeof(*chk), chksz);
		printf("%p: %d\n", chk, chksz);

		chk[0] = 0;
		chk[1] = 1;
		for (i = 2; i < chksz; i += 2)
			chk[i] = 1;
		for (i = 3; i < chksz; i += 3)
			chk[i] = 1;
		for (i = 5; i < chksz; i += 5)
			chk[i] = 1;

		for (i = 7; i < chksz; i++) {
			if (chk[i])
				continue;
			chk[i] = -1;
			for (j = i + i; j < chksz; j += i) {
				if (chk[j] == -2)
					continue;
				chk[j] = -2;
			}
		}
	}

	if (num < chksz) {
		if (chk[num] >= 1)
			return true;
		return false;
	} */

	while ((num > 1) && !(num & 0x1))
		num >>= 1;

	while ((num > 1) && !(num % 3))
		num /= 3;

	while ((num > 1) && !(num % 5))
		num /= 5;

	if (num == 1)
		return true;

	return false;
}
