#include <leetcode.h>

static int __ops[1000];
int calPoints(char** ops, int opsSize)
{
	int i, j;
	for (i = 0; i < opsSize; i++) {
		if (ops[i][0] == '-' ||
				((ops[i][0] >= '0') && (ops[i][0] <= '9'))) {
			for (j = (ops[i][0] == '-' ? 1 : 0), __ops[i] = 0; ops[i][j]; j++) {
				__ops[i] *= 10;
				__ops[i] += (ops[i][j] - '0');
			}
			if (ops[i][0] == '-')
				__ops[i] = -__ops[i];
		} else if (ops[i][0] == 'C') {
			__ops[i] = -30001;
			for (j = i - 1; j >= 0; j--) {
				if (__ops[j] < -30000)
					continue;
				__ops[j] = -30001;
				break;
			}
		} else {
			__ops[i] = 0;
		}
	}

	int sum = 0, prev1 = 0, prev2 = 0, tmp;
	for (i = 0; i < opsSize; i++) {
		if (__ops[i] < -30000)
			continue;
		if (ops[i][0] == '+')
			tmp = prev1 + prev2;
		else if (ops[i][0] == 'D')
			tmp = prev1 * 2;
		else
			tmp = __ops[i];
		sum += tmp;
		prev2 = prev1;
		prev1 = tmp;
	}
	return sum;
}

void tc_0(void)
{
	char *ops[] = {"5", "2", "C", "D", "+"};
	int opsSize = sizeof(ops) / sizeof(*ops);
	printf("30\n%d\n\n", calPoints(ops, opsSize));
}

void tc_1(void)
{
	char *ops[] = {"5","-2","4","C","D","9","+","+"};
	int opsSize = sizeof(ops) / sizeof(*ops);
	printf("27\n%d\n\n", calPoints(ops, opsSize));
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	return 0;
}

