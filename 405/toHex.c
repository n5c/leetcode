#include <stdio.h>
#include <stdlib.h>

char* toHex(int num)
{
	char *hstr, digit;
	char hexs[] = {"0123456789abcdef"};
	int i, j, chk;

	hstr = malloc(sizeof(*hstr) * (8 + 1));

	/*
	for (i = 0, j = 0, chk = 0; i < 8; i++) {
		digit = hexs[((num >> (28 - (i * 4))) & 0xf)];
		if (!chk && digit == '0')
			continue;
		hstr[j++] = digit;
		chk = 1;
	}

	if (!j)
		hstr[j++] = '0';
	hstr[j] = 0;
	*/

	if (num != 0) {
		char tmp[8];
		for (i = 7; i >= 0; i--) {
			tmp[i] = hexs[num & 0xf];
			num >>= 4;
		}

		for (i = 0; (i < 8) && (tmp[i] == '0'); i++);

		for (j = 0; i < 8; i++, j++)
			hstr[j] = tmp[i];
		hstr[j] = 0;
	} else {
		hstr[0] = '0';
		hstr[1] = 0;
	}

	return hstr;
}
