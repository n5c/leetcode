#include <leetcode.h>

static int map2Size;
static int map1[256];
static int map2[100];
static int moves[100][100];
int strangePrinter(char* s)
{
	int i, j, k, l, m, move;

	if (!s)
		return 0;

	if (!*s)
		return 0;

	map2Size = 0;
	for (i = 'a'; i <= 'z'; i++)
		map1[i] = -1;
	for (i = 0; s[i]; i++) {
		if (map1[s[i]] == -1) {
			map1[s[i]] = map2Size;
			map2[map2Size] = 0;
			map2Size++;
			continue;
		}
		if (s[i] == s[i - 1])
			continue;
		map2[map1[s[i]]] = map2Size;
		map2[map2Size] = 0;
		map1[s[i]] = map2Size;
		map2Size++;
	}

	memset(moves, 0, sizeof(moves));
	for (i = 0; i < map2Size; i++)
		moves[i][i] = 1;

	for (i = 2; i <= map2Size; i++) {
		k = map2Size - i;
		for (j = 0; j <= k; j++) {
			l = j + i - 1;
			moves[j][l] = 1 + moves[j + 1][l];
			if (!map2[j] || map2[j] > l)
				continue;

			for (m = map2[j]; m && m <= l; m = map2[m]) {
				move = moves[j + 1][m];
				if (m + 1 <= l)
					move += moves[m + 1][l];
				if (move < moves[j][l])
					moves[j][l] = move;
			}
		}
	}

	return moves[0][map2Size - 1];

}

void tc_0(void)
{
	printf("0\n%d\n\n", strangePrinter(""));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

