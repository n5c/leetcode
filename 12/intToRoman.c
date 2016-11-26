#include <stdio.h>
#include <stdlib.h>

#define CREATE_ROMANS(d1, d5, d10) {\
	"", #d1, #d1 #d1, #d1 #d1 #d1, #d1 #d5, #d5, \
	#d5 #d1, #d5 #d1 #d1, #d5 #d1 #d1 #d1, #d1 #d10 \
}

#define CREATE_ROMANS2(d1) {\
	"", #d1, #d1 #d1, #d1 #d1 #d1, #d1 #d1 #d1 #d1, #d1 #d1 #d1 #d1 #d1, \
	#d1 #d1 #d1 #d1 #d1 #d1, \
	#d1 #d1 #d1 #d1 #d1 #d1 #d1, \
	#d1 #d1 #d1 #d1 #d1 #d1 #d1 #d1, \
	#d1 #d1 #d1 #d1 #d1 #d1 #d1 #d1 #d1 \
}

char* intToRoman(int num) {
	int d, tmp;
	char tmpRomans[32];
	char *romans;
	char *romanDigits[][10] = {
		CREATE_ROMANS(I,V,X),
		CREATE_ROMANS(X,L,C),
		CREATE_ROMANS(C,D,M),
		CREATE_ROMANS2(M)
	};

	romans = calloc(1, 32);

	d = 0;
	while (num) {
		tmp = num % 10;
		snprintf(tmpRomans, 32, "%s%s", romanDigits[d][tmp], romans);
		snprintf(romans, 32, tmpRomans);
		num = num / 10;
		d++;
	}

	return romans;
}

