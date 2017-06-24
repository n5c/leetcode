#include <leetcode.h>

int findComplement(int num) {
	static const int comp[] = {
		1, 0, 1, 0, 3, 2, 1, 0,
		7, 6, 5, 4, 3, 2, 1, 0
	};

	if (num < 0)
		return 0;

	int shift = 28;
	unsigned int chk = 0xf0000000;

	while (shift) {
		if (num & chk)
			break;
		chk >>= 4;
		shift -= 4;
	}

	int c = comp[(num & chk) >> shift];
	if (shift) {
		unsigned int msk = ((1 << shift) - 1);
		c <<= shift;
		c |= (~(num & msk) & msk);
	}

	return c;
}

void tc_0(void)
{
	printf("%d\n", findComplement(5));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

