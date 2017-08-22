#include <leetcode.h>

static int steps[1001] = {0, 0, 2};
static int copys[1001] = {0, 0, 1};
int minSteps(int n)
{
	int i, j, k, s, c;
	if (!steps[0]) {
		steps[0] = 1;
		for (i = 2; i < 1000; i++) {
			for (c = copys[i], s = steps[i] + 1, k = i + c;
					k <= 1000; s++, k += c) {
				if (steps[k] && s >= steps[k])
					continue;
				steps[k] = s;
				copys[k] = c;
			}
			for (c = i, s = steps[i] + 2, k = c * 2;
					k <= 1000; s++, k += c) {
				if (steps[k] && s >= steps[k])
					continue;
				steps[k] = s;
				copys[k] = c;
			}
		}
	}

	return steps[n];
}

void tc_0(void)
{
	printf("7\n%d\n\n", minSteps(7));
	printf("28\n%d\n\n", minSteps(765));
	printf("21\n%d\n\n", minSteps(1000));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

