#include <leetcode.h>

const int moveXs[8] = {2, 2, 1, -1, -2, -2, -1, 1};
const int moveYs[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
static double chktbl[2][25][25];
double knightProbability(int N, int K, int r, int c)
{
	int i, j, k, l, x, y;
	double p;

	if (r < 0 || r >= N || c < 0 || c >= N)
		return 0.0;

	if (!K)
		return 1.0;

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			for (l = 0, chktbl[0][i][j] = 0.0; l < 8; ++l) {
				x = i + moveXs[l];
				if (x < 0 || x >= N)
					continue;
				y = j + moveYs[l];
				if (y < 0 || y >= N)
					continue;
				chktbl[0][i][j] += 1.0;

			}
			chktbl[0][i][j] /= 8.0;
		}
	}

	if (K == 1)
		return chktbl[0][r][c];

	int k1 = 1;
	int k2 = 0;
	for (k = 2; k <= K; ++k) {
		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				for (l = 0, chktbl[k1][i][j] = 0.0; l < 8; ++l) {
					x = i + moveXs[l];
					if (x < 0 || x >= N)
						continue;
					y = j + moveYs[l];
					if (y < 0 || y >= N)
						continue;
					chktbl[k1][i][j] += chktbl[k2][x][y];
				}
				chktbl[k1][i][j] /= 8.0;
			}
		}
		k1 ^= 1;
		k2 ^= 1;
	}

	return chktbl[k2][r][c];
}

void tc_0(void)
{
	printf("0.0625\n%0.5f\n\n", knightProbability(3,2,0,0));
	printf("0.00019\n%0.5f\n\n", knightProbability(8,30,6,4));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

