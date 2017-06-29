#include <leetcode.h>

int maxCount(int m, int n, int** ops, int opsRowSize, int opsColSize)
{
	int i, mini = INT_MAX, minj = INT_MAX;
	for (i = 0; i < opsRowSize; i++) {
		if (ops[i][0] < mini)
			mini = ops[i][0];
		if (ops[i][1] < minj)
			minj = ops[i][1];
	}

	if (mini > m)
		mini = m;
	if (minj > n)
		minj = n;

	return mini * minj;
}

void tc_0(void)
{
	int _ops[][2] = {{2,2},{3,3}};
	int *ops[] = {_ops[0], _ops[1]};
	int opsRowSize = sizeof(_ops)/sizeof(*_ops);
	int opsColSize = sizeof(*_ops)/sizeof(**_ops);
	printf("4\n%d\n", maxCount(3, 3, ops, opsRowSize, opsColSize));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

