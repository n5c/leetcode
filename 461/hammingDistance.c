#include <leetcode.h>

int hammingDistance(int x, int y)
{
	int output = x ^ y;
	output = ((output & 0x55555555) + ((output & 0xaaaaaaaa) >> 1));
	output = ((output & 0x33333333) + ((output & 0xcccccccc) >> 2));
	output = ((output & 0x0f0f0f0f) + ((output & 0xf0f0f0f0) >> 4));
	output = ((output & 0x00ff00ff) + ((output & 0xff00ff00) >> 8));
	output = ((output & 0x0000ffff) + ((output & 0xffff0000) >> 16));
	return output;
}

void tc_0(void)
{
	int x = 1, y = 4;
	printf("2\n");
	printf("%d\n", hammingDistance(x,y));

	x = 808464432;
	y = 2147483648;
	printf("9\n");
	printf("%d\n", hammingDistance(x,y));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

