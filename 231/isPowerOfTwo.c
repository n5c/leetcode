#include <stdio.h>

#define bool int
#define true 1
#define false 0

bool isPowerOfTwo(int n)
{
	if (n <= 0)
		return false;
	return !(n & (n - 1));
}
