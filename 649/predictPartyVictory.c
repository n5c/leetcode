#include <leetcode.h>

char* predictPartyVictory(char* senate)
{
	int i, j;
	int RDs[256];
	int bans[256] = {['D'] = 0, ['R'] = 0};
	int maps[256] = {['D'] = 'R', ['R'] = 'D'};
	char c;
	while (1) {
		RDs['R'] = 0;
		RDs['D'] = 0;
		for (i = 0; (c = senate[i]); i++) {
			if (c == '_')
				continue;
			if (bans[maps[c]]) {
				bans[maps[c]]--;
				senate[i] = '_';
				continue;
			}
			RDs[c]++;
			bans[c]++;
		}
		RDs['R'] -= bans['D'];
		if (RDs['R'] < 0)
			RDs['R'] = 0;
		RDs['D'] -= bans['R'];
		if (RDs['D'] < 0)
			RDs['D'] = 0;
		if (RDs['R'] * 2 < RDs['D'])
			return strdup("Dire");
		if (RDs['D'] * 2 < RDs['R'])
			return strdup("Radiant");
		if (!RDs['R'] || !RDs['D'])
			break;
	}
	if (RDs['R'])
		return strdup("Radiant");
	return strdup("Dire");
}

void tc_0(void)
{
	char *s;
	char s1[] = "RDDR";
	s = predictPartyVictory(s1);
	printf("Radiant\n%s\n\n", s);
	free(s);
	char s2[] = "RDDRDRDRDRRDRDDRRDRDDRRDDRRD";
	s = predictPartyVictory(s2);
	printf("Dire\n%s\n\n", s);
	free(s);
	char s3[] = "RDDRRDRDRDDRDRDRDRDRDRDRDRDRDR";
	s = predictPartyVictory(s3);
	printf("Dire\n%s\n\n", s);
	free(s);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

