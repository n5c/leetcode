#include <stdio.h>
#include <string.h>

int countBattleships(char** board, int boardRowSize, int boardColSize)
{
	int i, j, k, ships = 0;

	for (i = 0; i < boardRowSize; i++) {
		for (j = 0; j < boardColSize; j++)
			printf("%c", board[i][j]);
		printf("\n");
	}

	for (i = 0; i < boardRowSize; i++) {
		for (j = 0; j < boardColSize; j++) {
			if (board[i][j] == '.')
				continue;
			if (i && (board[i - 1][j] != '.'))
				continue;

			for (k = (j + 1); k < boardColSize; k++) {
				if (board[i][k] != board[i][j])
					break;
			}
			j = k - 1;
			ships++;
		}
	}

	return ships;
}

void test_case_0(void)
{
	char *board[] = {
		".....................X........",
		"..X.X.........................",
		"..X..........X.......X........",
		"..X.XXXXXXXX.X.XXX...X........",
		".............X....X..X........",
		".......XXXXX.X....X..X........",
		".............X....X..X........",
		"..................X...........",
		"..................X..X........",
		".............................."
	};
	int boardRowSize = sizeof(board)/sizeof(*board);
	int boardColSize = strlen(board[0]);
	int ships;

	ships = countBattleships(board, boardRowSize, boardColSize);
	printf("%d\n", ships);
}

void test_case_1(void)
{
	char *board[] = {
		"X..X",
		"...X",
		"...X"
	};
	int boardRowSize = sizeof(board)/sizeof(*board);
	int boardColSize = strlen(board[0]);
	int ships;

	ships = countBattleships(board, boardRowSize, boardColSize);
	printf("%d\n", ships);
}

int main(int argc, char *argv[])
{
	test_case_1();
	return 0;
}

