#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int climbStairs(int n)
{
	static int *ways = NULL, waysz = 1024;
	int i;

	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;

	if (!ways || (n >= waysz)) {
		int *tmp;
		i = 0;
		while (n >= (waysz << i)) i++;
		tmp = malloc(sizeof(*tmp) * (waysz << i));
		if (ways) {
			memcpy(tmp, ways, sizeof(*ways) * (waysz));
			memset(((char *)tmp + sizeof(*ways)*(waysz)),
				0, (sizeof(*ways) * (waysz << i) - waysz));
			waysz <<= i;
		} else {
			memset(tmp, 0, sizeof(*tmp) * (waysz << i));
			ways = tmp;
			waysz <<= i;
			ways[0] = 0;
			ways[1] = 1;
			ways[2] = 2;
		}
	}

	if (ways[n])
		return ways[n];

	for (i = 3; i <= n; i++)
		ways[i] = ways[i - 1] + ways[i - 2];

	return ways[n];
}

int main(int argc, char *argv[])
{
	printf("%d\n", climbStairs(10));
}

