#include <leetcode.h>

static long long counts[100000];
int numDecodings(char* s)
{
	int i;
	long long count;

	if (s[0] == '0')
		return 0;
	else if (s[0] == '*') {
		if (s[1] && s[1] == '0')
			counts[0] = 2;
		else
			counts[0] = 9;

	} else {
		counts[0] = 1;

	}

	if (!s[1])
		return counts[0];

	if (s[1] == '0') {
		if (s[0] != '*' && s[0] != '1' && s[0] != '2')
			return 0;
		counts[1] = counts[0];

	} else if (s[2] && s[2] == '0') {
		if (s[1] == '*')
			counts[1] = counts[0] * 2;
		else
			counts[1] = counts[0];

	} else if (s[1] == '*') {
		if (s[0] == '*')
			counts[1] = 96; /* 81 + 9 + 6 */
		else if (s[0] == '1')
			counts[1] = 18; /* 9 + 9 */
		else if (s[0] == '2')
			counts[1] = 15; /* 9 + 6 */
		else
			counts[1] = 9;

	} else {
		counts[1] = counts[0];
		if (s[0] == '*') {
			if (s[1] >= '1' && s[1] <= '6')
				counts[1] += 2;
			else
				counts[1] += 1;

		} else if (s[0] == '1') {
			counts[1] += 1;

		} else if (s[0] == '2' && (s[1] >= '1' && s[1] <= '6')) {
			counts[1] += 1;

		}

	}

	if (!s[2])
		return counts[1];

	for (i = 2; s[i]; i++) {
		if (s[i] == '0') {
			if (s[i - 1] != '*' && s[i - 1] != '1' && s[i - 1] != '2')
				return 0;
			counts[i] = counts[i - 1];

		} else if (s[i + 1] && s[i + 1] == '0') {
			if (s[i] == '*')
				counts[i] = counts[i - 1] * 2;
			else
				counts[i] = counts[i - 1];

		} else if (s[i] == '*') {
			counts[i] = counts[i - 1] * 9;
			if (s[i - 1] == '*')
				counts[i] += counts[i - 2] * 15;
			else if (s[i - 1] == '1')
				counts[i] += counts[i - 2] * 9;
			else if (s[i - 1] == '2')
				counts[i] += counts[i - 2] * 6;

		} else {
			counts[i] = counts[i - 1];
			if (s[i - 1] == '*') {
				if (s[i] >= '1' && s[i] <= '6')
					counts[i] += counts[i - 2] * 2;
				else
					counts[i] += counts[i - 2];

			} else if (s[i - 1] == '1') {
				counts[i] += counts[i - 2];

			} else if (s[i - 1] == '2' && (s[i] >= '1' && s[i] <= '6')) {
				counts[i] += counts[i - 2];

			}

		}
		counts[i] = (counts[i] % (long long)1000000007);

	}

	return (int)counts[i - 1];

}

void tc_0(void)
{
	printf("0\n%d\n\n", numDecodings("0"));
	printf("365395042\n%d\n\n", numDecodings(
				"**1*2*3*4*5*6*7*8*9*10*02*20**"));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

