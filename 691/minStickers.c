#include <leetcode.h>

static uint8_t __stksSize;
static uint8_t __stksTotalSize;
static uint8_t (*__stks)[16];
static uint8_t __targetSize;
static uint8_t __target[16];
static int __chktbl[(1 << 15)];
int backtrack(uint8_t *target)
{
	int min = INT_MAX;
	uint8_t i, j;
	uint16_t chkIndex = 0;

	for (i = 1; i <= __targetSize; ++i) {
		chkIndex <<= __target[i];
		if (!target[i])
			continue;
		chkIndex |= ((1 << target[i]) - 1);

	}
	if (__chktbl[chkIndex])
		return __chktbl[chkIndex];

	for (i = 0; i < __stksSize; ++i) {
		uint8_t tmp[__targetSize + 1];
		for (j = 1, tmp[0] = target[0]; j <= __targetSize; ++j) {
			if (target[j] > __stks[i][j]) {
				tmp[0] -= __stks[i][j];
				tmp[j] = target[j] - __stks[i][j];

			} else {
				tmp[0] -= target[j];
				tmp[j] = 0;

			}

		}
		if (!tmp[0]) {
			min = 1;
			break;

		} else if (tmp[0] != target[0]) {
			int s = backtrack(tmp) + 1;
			if (s && s < min)
				min = s;

		}

	}
	if (min == INT_MAX)
		min = -1;
	__chktbl[chkIndex] = min;
	return min;

}

int minStickers(char** stickers, int stickersSize, char* target)
{
	int8_t i, j, k;
	uint8_t map[26] = {0};

	memset(__target, 0, sizeof(__target));

	for (i = 0, __targetSize = 0; target[i]; ++i) {
		j = (uint8_t)(target[i] - 'a');
		if (!map[j]) {
			++__targetSize;
			map[j] = __targetSize;

		}
		++__target[map[j]];
		++__target[0];

	}

	memset(__chktbl, 0, (sizeof(*__chktbl) * (1 << __target[0])));

	if (stickersSize > __stksTotalSize) {
		__stksTotalSize = stickersSize;
		__stks = realloc(__stks, sizeof(*__stks) * __stksTotalSize);

	}
	for (i = 0, __stksSize = 0; i < stickersSize; ++i) {
		uint8_t index, count = 0, tmp[16] = {0};
		for (j = 0; stickers[i][j]; ++j) {
			index = stickers[i][j] - 'a';
			if (!map[index])
				continue;
			++tmp[map[index]];
			++count;

		}
		if (!count)
			continue;
		for (j = 0; j <= __targetSize; ++j) {
			if (tmp[j] >= __target[j])
				tmp[j] = __target[j];
			__stks[__stksSize][j] = tmp[j];

		}
		__stksSize++;

	}

	if (!__stksSize)
		return -1;

	return backtrack(__target);

}

void tc_0(void)
{
	char *stickers[] = {"with", "example", "science"};
	int stickersSize = sizeof(stickers) / sizeof(*stickers);
	char target[] = "thehat";
	printf("3\n%d\n\n", minStickers(stickers, stickersSize, target));
}

void tc_1(void)
{
	char *stickers[] = {"notice", "possible"};
	int stickersSize = sizeof(stickers) / sizeof(*stickers);
	char target[] = "basicbasic";
	printf("-1\n%d\n\n", minStickers(stickers, stickersSize, target));
}

void tc_2(void)
{
	char *stickers[] = {"these","guess","about","garden","him"};
	int stickersSize = sizeof(stickers) / sizeof(*stickers);
	char target[] = "atomher";
	printf("3\n%d\n\n", minStickers(stickers, stickersSize, target));
}

void tc_3(void)
{
	char *stickers[] = {"bring","plane","should","against","chick"};
	int stickersSize = sizeof(stickers) / sizeof(*stickers);
	char target[] = "greatscore";
	printf("7\n%d\n\n", minStickers(stickers, stickersSize, target));
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	tc_2();
	tc_3();
	return 0;
}

