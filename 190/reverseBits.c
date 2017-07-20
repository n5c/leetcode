#include <leetcode.h>

static uint8_t *rbits;
uint32_t reverseBits(uint32_t n)
{
	if (!rbits) {
		int i, j;
		uint8_t c;
		rbits = malloc(sizeof(*rbits) * 256);
		for (i = 0; i < 256; i++) {
			c = (uint8_t)i;
			for (j = 0, rbits[i] = 0; j < 7; j++) {
				rbits[i] |= c & 0x1;
				c >>= 1;
				rbits[i] <<= 1;
			}
			rbits[i] |= c & 0x1;
		}
	}
	return (((uint32_t)rbits[n & 0xff] << 24) |
		((uint32_t)rbits[(n & 0xff00) >> 8] << 16) |
		((uint32_t)rbits[(n & 0xff0000) >> 16] << 8) |
		((uint32_t)rbits[(n & 0xff000000) >> 24]));
}

void tc_0(void)
{
	printf("964176192\n%u\n\n", reverseBits(43261596));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

