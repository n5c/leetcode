#include <leetcode.h>

char* getHint(char* secret, char* guess)
{
	int i, j, schk[10], gchk[10], bull, cow;
	char ans[20], *hint;

	for (i = 0; i < 10; i++) {
		schk[i] = 0;
		gchk[i] = 0;
	}

	for (i = 0, bull = 0; guess[i]; i++) {
		if (guess[i] == secret[i]) {
			bull++;
			schk[secret[i] - '0']--;
			gchk[guess[i] - '0']--;
		}

		schk[secret[i] - '0']++;
		gchk[guess[i] - '0']++;
	}

	for (i = 0, cow = 0; i < 10; i++) {
		if (!schk[i])
			continue;
		j = (gchk[i] > schk[i]) ? schk[i] : gchk[i];
		cow += j;
	}

	snprintf(ans, 20, "%dA%dB", bull, cow);
	hint = malloc(sizeof(*hint) * (strlen(ans) + 1));
	strcpy(hint, ans);
	return hint;
}

void tc_0(void)
{
	char secret[] = "1807";
	char guess[]  = "7810";
	char *hint = getHint(secret, guess);
	printf("1A3B\n");
	printf("%s\n", hint);
	free(hint);
}

void tc_1(void)
{
	char secret[] = "18079999999999999999999992222222222222222225555555555555555555555555555555581111111111333456789";
	char guess[]  = "78102222222222227777777777777777666666666666666111111111111111111456789999999999999999999999774";
	char *hint = getHint(secret, guess);
	printf("3A50B\n");
	printf("%s\n", hint);
	free(hint);
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	return 0;
}

