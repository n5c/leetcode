#include <leetcode.h>

char* nextClosestTime(char* time) {
	int i, j, k, l, chk[10] = {0}, digits[4], digitsLen;

	chk[time[0] - '0'] = 1;
	chk[time[1] - '0'] = 1;
	chk[time[3] - '0'] = 1;
	chk[time[4] - '0'] = 1;
	for (i = 0, j = 0; i < 10; i++) {
		if (!chk[i])
			continue;
		digits[j] = i;
		j++;
	}
	digitsLen = j;

	for (i = 0; i < digitsLen && digits[i] != (time[4] - '0'); i++);
	for (j = 0; j < digitsLen && digits[j] != (time[3] - '0'); j++);
	for (k = 0; k < digitsLen && digits[k] != (time[1] - '0'); k++);
	for (l = 0; l < digitsLen && digits[l] != (time[0] - '0'); l++);

	while (1) {
		i++;
		if (i >= digitsLen) {
			i = 0;
			j++;
		}
		if (j >= digitsLen) {
			j = 0;
			k++;
		}
		if (k >= digitsLen) {
			k = 0;
			l++;
		}
		if (l >= digitsLen) {
			l = 0;
		}
		int tmp1 = ((digits[j] * 10) + digits[i]);
		if (tmp1 >= 60)
			continue;
		int tmp2 = ((digits[l] * 10) + digits[k]);
		if (tmp2 >= 24) {
			if (tmp2 == 24 && tmp1 == 0)
				break;
			continue;
		}
		break;
	}

	char *next = malloc(sizeof(*next) * 6);
	next[0] = digits[l] + '0';
	next[1] = digits[k] + '0';
	next[2] = ':';
	next[3] = digits[j] + '0';
	next[4] = digits[i] + '0';
	next[5] = 0;
	return next;
}

void tc_0(void)
{
	char *time = nextClosestTime("19:34");
	printf("19:39\n%s\n\n", time);
	free(time);
	time = nextClosestTime("02:40");
	printf("02:42\n%s\n\n", time);
	free(time);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

