#include <leetcode.h>

bool isPerfectSquare(int num)
{
	static int primes[65536];
	static int primesSize = 0;
	int i, j;

	if (!primesSize) {
		int tmp[65536] = {0};
		for (i = 3; i < 65536; i += 2) {
			if (tmp[i])
				continue;
			tmp[i] = 1;
			for (j = i << 1; j < 65536; j += i)
				tmp[j] = -1;
		}

		primes[0] = 2;
		for (i = 3, j = 1; i < 65536; i += 2) {
			if (tmp[i] != 1)
				continue;
			primes[j++] = i;
		}

		primesSize = j;
	}

	while (num) {
		if (num & 0x1)
			break;
		if (num & 0x2)
			return false;
		num >>= 2;
	}

	for (i = 1, j = primes[i] * primes[i]; i < primesSize && j <= num; i++, j = primes[i] * primes[i]) {
		while (num) {
			if (num % primes[i])
				break;
			if (num % j)
				return false;
			num /= j;
		}
	}

	if (num == 1)
		return true;

	return !num;
}

void tc_0(void)
{
	printf("%s\n", isPerfectSquare(16) ? "true" : "false");
	printf("%s\n", isPerfectSquare(9) ? "true" : "false");
	printf("%s\n", isPerfectSquare(2147483647) ? "true" : "false");
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

