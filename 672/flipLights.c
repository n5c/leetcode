#include <leetcode.h>

static int init;
static int status[1001];
const int ops[4] = {0xf, 0x5, 0xa, 0x9};
int flipLights(int n, int m)
{
	int i, j, chk, msk;

	if (!m)
		return 1;

	if (!init) {
		init = 1;
		status[0] = (1 << 0xf);
		for (i = 1; i < 1001; i++) {
			for (chk = status[i - 1], j = 0; chk; chk >>= 1, j++) {
				if (!(chk & 1))
					continue;
				status[i] |= (1 << (j ^ ops[0]));
				status[i] |= (1 << (j ^ ops[1]));
				status[i] |= (1 << (j ^ ops[2]));
				status[i] |= (1 << (j ^ ops[3]));

			}

		}

	}

	if (!n || !m)
		return 1;

	chk = status[m];
	if (n < 4) {
		i = (1 << n);
		msk = (i - 1);
		for (; i < 16; i++) {
			if (!(chk & (1 << i)))
				continue;
			chk |= (1 << (i & msk));
			chk &= ~(1 << i);

		}

	}

	for (i = 0; chk; chk >>= 1) {
		if (!(chk & 1))
			continue;
		i++;

	}

	return i;

}

/*
   1,2,3,4,   5,6,7,8,9,10,11,12,13, ...
   1,  3,     5,  7,  9,   11,   13, ...
     2,  4,     6,  8,  10,   12,    ...
   1,    4,       7,    10,      13, ...

   1111
0: 1111
1: 0000, 0101, 1010, 0110
2: 1111, 1010, 0101, 1001, 0000, 1100, 0011, 1001
*/

void tc_0(void)
{
	printf("2\n%d\n\n", flipLights(1,1));
	printf("3\n%d\n\n", flipLights(2,1));
	printf("4\n%d\n\n", flipLights(3,1));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

