int isValidSudoku(char** board, int boardRowSize, int boardColSize)
{
	int i, j, check;
	int check_row[9] = {0};
	int check_col[9] = {0};
	int check_box[9] = {0};
	const static int map[9][9] = {
		{0, 0, 0, 1, 1, 1, 2, 2, 2},
		{0, 0, 0, 1, 1, 1, 2, 2, 2},
		{0, 0, 0, 1, 1, 1, 2, 2, 2},
		{3, 3, 3, 4, 4, 4, 5, 5, 5},
		{3, 3, 3, 4, 4, 4, 5, 5, 5},
		{3, 3, 3, 4, 4, 4, 5, 5, 5},
		{6, 6, 6, 7, 7, 7, 8, 8, 8},
		{6, 6, 6, 7, 7, 7, 8, 8, 8},
		{6, 6, 6, 7, 7, 7, 8, 8, 8}};

	for (i = 0; i < boardRowSize; i++) {
		for (j = 0; j < boardColSize; j++) {
			if (board[i][j] == '.')
				continue;
			check = (1 << (board[i][j] - '0' - 1));
			if (check_row[i] & check)
				return 0;
			check_row[i] |= check;

			if (check_col[j] & check)
				return 0;
			check_col[j] |= check;

			if (check_box[map[i][j]] & check)
				return 0;
			check_box[map[i][j]] |= check;
		}
	}

	return 1;
}

