#define bool int
#define true 1
#define false 0

bool isPowerOfFour(int num)
{
	while ((num > 1) && !(num & 0x3))
		num >>= 2;
	return (num == 1);
}

