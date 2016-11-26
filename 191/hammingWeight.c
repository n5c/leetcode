#include <stdio.h>
#include <stdint.h>

int hammingWeight(uint32_t n)
{
	const int bitcnt[] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
	int cnt = 0;
	while (n) {
		cnt += bitcnt[n & 0xf];
		n >>= 4;
	}
	return cnt;
}

int main(int argc, char *argv[])
{
	uint32_t n = 0xfff000ab;
	if (argc == 2)
		sscanf(argv[1], "%d", &n);
	printf("%d\n", hammingWeight(n));
}

