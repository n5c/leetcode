#include <stdio.h>

#define bool int
#define true 1
#define false 0

bool isPowerOfThree(int n)
{
	if (n <= 0)
		return false;

	while (n > 1) {
		if (n % 3)
			return false;
		n /= 3;
	}

	return true;
}

