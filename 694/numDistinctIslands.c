#include <leetcode.h>

static struct island
{
	int x;
	int y;

} islands[2000];

void updIsland(int **grid, int gridRowSize, int gridColSize, int x, int y)
{
	grid[x][y] = 2;
	if (x - 1 >= 0 && grid[x - 1][y] == 1)
		updIsland(grid, gridRowSize, gridColSize, x - 1, y);
	if (x + 1 < gridRowSize && grid[x + 1][y] == 1)
		updIsland(grid, gridRowSize, gridColSize, x + 1, y);
	if (y - 1 >= 0 && grid[x][y - 1] == 1)
		updIsland(grid, gridRowSize, gridColSize, x, y - 1);
	if (y + 1 < gridColSize && grid[x][y + 1] == 1)
		updIsland(grid, gridRowSize, gridColSize, x, y + 1);
}

bool isSame(int **grid, int gridRowSize, int gridColSize, int x1, int y1, int x2, int y2)
{
	grid[x1][y1] += 10000;
	if ((x1 - 1) >= 0) {
		if (grid[x1 - 1][y1]) {
			if (x2 - 1 < 0)
				goto __FALSE;
			if (!grid[x2 - 1][y2])
				goto __FALSE;
			if (grid[x1 - 1][y1] == 2 && !isSame(grid, gridRowSize, gridColSize, x1 - 1, y1, x2 - 1, y2))
				goto __FALSE;
		} else {
			if ((x2 - 1 >= 0) && grid[x2 - 1][y2])
				goto __FALSE;
		}
	} else {
		if (((x2 - 1) >= 0) && grid[x2 - 1][y2])
			goto __FALSE;
	}

	if ((x1 + 1) < gridRowSize) {
		if (grid[x1 + 1][y1]) {
			if (x2 + 1 >= gridRowSize)
				goto __FALSE;
			if (!grid[x2 + 1][y2])
				goto __FALSE;
			if (grid[x1 + 1][y1] == 2 && !isSame(grid, gridRowSize, gridColSize, x1 + 1, y1, x2 + 1, y2))
				goto __FALSE;
		} else {
			if ((x2 + 1 < gridRowSize) && grid[x2 + 1][y2])
				goto __FALSE;
		}
	} else {
		if (((x2 + 1) < gridRowSize) && grid[x2 + 1][y2])
			goto __FALSE;
	}

	if ((y1 - 1) >= 0) {
		if (grid[x1][y1 - 1]) {
			if (y2 - 1 < 0)
				goto __FALSE;
			if (!grid[x2][y2 - 1])
				goto __FALSE;
			if (grid[x1][y1 - 1] == 2 && !isSame(grid, gridRowSize, gridColSize, x1, y1 - 1, x2, y2 - 1))
				goto __FALSE;
		} else {
			if ((y2 - 1 >= 0) && grid[x2][y2 - 1])
				goto __FALSE;
		}
	} else {
		if ((y2 - 1 >= 0) && grid[x2][y2 - 1])
			goto __FALSE;
	}

	if ((y1 + 1) < gridColSize) {
		if (grid[x1][y1 + 1]) {
			if (y2 + 1 >= gridColSize)
				goto __FALSE;
			if (!grid[x2][y2 + 1])
				goto __FALSE;
			if (grid[x1][y1 + 1] == 2 && !isSame(grid, gridRowSize, gridColSize, x1, y1 + 1, x2, y2 + 1))
				goto __FALSE;
		} else {
			if ((y2 + 1 < gridColSize) && grid[x2][y2 + 1])
				goto __FALSE;
		}
	} else {
		if ((y2 + 1 < gridColSize) && grid[x2][y2 + 1])
			goto __FALSE;
	}

	grid[x1][y1] -= 10000;
	return true;

__FALSE:
	grid[x1][y1] -= 10000;
	return false;
}

int numDistinctIslands(int** grid, int gridRowSize, int gridColSize)
{
	int i, j, k, islandId = 0;
	memset(islands, 0, sizeof(*islands));

	for (i = 0; i < gridRowSize; ++i) {
		for (j = 0; j < gridColSize; ++j) {
			if (grid[i][j] != 1)
				continue;
			islands[islandId].x = i;
			islands[islandId].y = j;
			updIsland(grid, gridRowSize, gridColSize, i, j);
			for (k = 0; k < islandId; ++k) {
				if (isSame(grid, gridRowSize, gridColSize, i, j, islands[k].x, islands[k].y))
					break;

			}
			if (k == islandId)
				++islandId;

		}

	}

	return islandId;

}

void tc_0(void)
{
	int __grid[][50] = {
		{1,1,0,1,0,1,0,0,1,1,1,0,1,1,0,0,0,0,1,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,1,1,0,0,0,1,1,1,0,0,1,0,1,1,0,0},
		{1,0,0,0,1,1,0,0,1,0,1,0,1,1,0,0,1,0,1,1,0,1,1,0,0,0,0,1,1,1,0,0,1,1,0,1,1,1,0,1,1,0,0,1,0,0,1,0,0,1},{0,1,1,1,0,0,0,0,1,0,1,1,0,0,1,1,0,1,1,0,0,0,0,1,1,0,1,1,0,0,0,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,0},{1,1,1,1,1,0,0,0,1,1,0,0,1,0,0,1,1,0,1,0,1,0,1,1,0,1,0,1,1,1,0,0,1,1,0,1,0,0,1,0,0,0,0,1,0,1,1,1,1,1},{1,1,0,1,1,1,0,1,1,1,0,1,0,1,1,0,0,0,0,1,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1},{0,1,1,1,1,0,1,0,1,1,0,0,0,1,1,0,1,0,1,0,1,1,1,1,0,0,1,1,0,0,0,0,0,1,0,1,1,1,0,0,0,1,1,1,1,0,0,0,1,0},{0,1,1,0,1,1,0,0,0,1,1,0,0,1,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,0,1,0,0,1,1,0,1,1,0},{0,1,0,0,1,0,1,1,1,1,0,0,0,1,0,1,1,0,1,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,1,0,1,0,0,1},{0,1,1,0,1,0,1,0,0,1,1,1,1,1,1,1,1,1,0,1,0,0,1,1,1,1,1,1,0,1,1,1,1,0,0,1,1,0,1,0,1,1,0,0,1,0,0,1,0,1},{0,1,0,0,1,1,1,0,0,1,0,0,0,0,0,0,1,1,1,0,1,0,0,0,0,1,1,1,1,0,1,1,0,1,1,1,1,0,0,0,1,1,0,1,0,1,1,1,1,1},{0,0,0,0,1,1,1,1,1,0,0,1,0,1,1,0,1,0,1,0,0,1,1,1,1,1,1,1,1,0,1,0,1,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,0},{1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,0,1,1,1,0,1,1,1,1,0,0,1,1,1,0,0,1,0,0,1,1,0,1,1,1,0,0,1,1,0,1},{1,0,1,0,1,1,0,1,0,1,0,0,0,1,1,1,1,0,0,0,0,1,0,1,1,1,1,1,1,1,0,0,1,0,1,1,0,0,1,0,0,0,1,0,1,1,1,1,1,0},{1,0,0,0,0,0,0,0,1,0,1,1,0,0,0,1,1,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,1,0,1},{0,1,0,0,0,1,0,1,0,1,0,0,1,0,0,1,1,0,0,1,0,1,0,0,1,1,1,0,0,0,1,0,1,1,0,0,0,0,1,0,0,0,1,1,0,1,1,0,1,0},{0,0,1,0,0,1,0,1,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,0,0,1,0,0,1,0,1,1,1,0,0,0,1,1,0,1,0,1,0,1,0,1,0,0,1,0},{1,0,0,0,1,1,0,1,0,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,0,0,1,0,0,0,0,1,1,1,0,1,1,1,0,1,0,1,1,0,1,1,1,1,0},{1,0,0,0,0,0,1,1,1,1,0,0,0,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,0,0,1},{0,1,0,0,0,0,0,0,1,0,0,1,1,1,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,1,1,0,1,1,1,0,0,0,0},{0,1,1,0,1,1,0,0,0,0,0,1,0,1,0,0,1,1,1,1,0,0,0,1,1,1,1,0,1,1,0,1,1,1,0,1,1,0,1,0,0,1,0,0,0,1,0,1,1,1},{0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,1,1,1,0,1,1,0,1,1,1,0,1,1,0,0,1,0,1,0,1,1,0,1,1,1,1,1,0,1,0,1,0,1,0},{0,0,0,0,1,1,1,1,0,0,0,1,1,0,0,1,0,0,1,1,0,1,0,1,1,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1},{1,0,0,0,1,1,0,0,0,1,0,1,1,0,1,1,0,1,0,1,1,0,0,0,1,1,0,0,1,0,0,0,0,1,1,0,0,1,1,1,0,0,0,1,1,0,0,1,1,0},{0,1,1,1,0,0,0,0,1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,1,0,0,1,0,1,1,1,0,0,1,0,1},{1,1,1,0,1,0,0,1,1,1,0,1,1,1,0,1,1,0,0,1,1,0,1,0,0,0,0,0,1,1,1,0,0,1,0,1,0,0,0,1,1,1,1,1,0,1,0,1,0,1},{0,0,1,1,1,1,1,0,1,0,1,1,0,1,0,1,0,1,1,1,0,0,0,1,1,0,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0},{1,1,0,0,1,1,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,1,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,0,1,1,0,0,0,1,1,0,1,0,1,1},{1,1,0,1,1,1,0,1,1,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,1,1,0,0,1,0,1,1,1,0,1,0,0,1,0,1,0,1,1,1,1,0,0,0},{0,0,0,0,0,1,1,1,0,0,1,0,1,0,1,0,1,0,0,0,0,1,1,1,0,1,1,0,1,1,0,1,1,0,1,0,1,0,0,0,0,1,0,1,1,1,1,1,0,0},{0,1,1,1,1,1,0,1,0,1,1,0,0,1,0,0,1,1,1,1,1,1,0,0,1,0,0,0,0,1,1,0,0,1,1,0,1,1,0,0,1,0,1,0,0,1,0,0,1,0},{1,0,1,1,1,0,1,0,1,1,1,0,0,1,1,1,0,0,1,1,0,1,1,0,0,0,1,0,0,1,0,0,1,0,1,1,1,1,0,1,0,1,1,0,0,1,1,1,0,1},{0,0,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,0,1,1,0,1,1,1,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,0,1,0,0,1},{0,1,1,0,1,0,0,0,1,0,1,0,0,1,1,0,1,1,0,0,1,1,0,0,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,1,1,0,0,0,1,0,0,0,1,1},{0,0,1,0,1,1,0,0,1,0,1,0,0,1,0,1,1,0,1,0,0,1,1,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,1,1,0,1,0,0,1,1},{0,0,0,1,0,0,0,0,0,1,1,1,0,0,1,0,0,1,1,1,0,1,0,0,1,1,1,0,1,1,0,1,1,0,1,0,1,1,0,0,1,0,0,0,1,1,0,1,0,1},{1,1,1,1,1,0,1,0,0,1,0,0,0,1,1,1,0,0,1,0,1,0,1,0,1,1,0,1,0,1,0,0,1,1,1,1,0,1,1,0,1,1,0,1,1,1,0,1,0,1},{0,1,0,0,1,0,0,1,1,0,0,1,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,1,0,1,1,0,1,0,1,0,1,0,0,0,0,1,1,0,1,1,0,0,1,0},{0,0,0,1,1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,1,1,0,1,1,1,0,1,1,0,1,0,1,0,0,1,1,0,0,0,0,1,1,0,1,1,0,0,1,1},{0,1,1,1,0,1,1,1,1,0,1,1,1,0,0,1,0,0,1,0,0,1,1,0,0,0,0,1,0,0,0,1,0,0,1,1,1,1,0,1,0,1,1,0,1,0,0,0,1,1},{1,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,1,1,1,0,1,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,1,1},{0,0,0,0,1,1,0,1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,1,0,0,1,0,1,1,0,0,1,0,0,1,1,1,0,1},{1,1,1,1,0,1,1,0,0,1,0,0,1,1,0,1,1,0,0,0,0,0,1,0,0,0,0,1,0,0,1,1,1,1,0,1,0,0,0,0,0,0,1,0,0,1,0,0,1,1},{0,0,1,1,0,1,1,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,0,1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,1,0,1,0,1,1,0,1,1,0},{0,1,0,0,1,0,0,0,1,0,1,1,1,1,1,1,0,1,0,1,1,0,0,1,1,0,1,1,1,1,1,1,0,1,0,1,1,0,0,0,0,1,1,0,0,1,0,1,1,1},{0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,1,0,0,0,1,1,1,1,1,0,1,1,1,0,0,1,0,0,0,1,0,0,1,1,0,1,0,0,0,1,1,1,0,0},{0,1,1,0,0,1,0,0,1,1,0,1,1,0,0,1,0,1,1,0,1,0,0,0,1,0,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,0},{1,0,0,1,0,0,1,1,1,1,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,1,0,1,0,1,1,1,0,1,1,0,0,1,1,1,1,0,0,1,1,1,0,0,1,1},{0,1,0,1,0,0,1,1,1,0,1,0,0,0,0,1,1,1,0,1,0,1,1,1,1,1,0,1,0,0,1,1,0,0,1,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1},{1,0,1,0,0,1,1,0,0,1,1,1,1,1,0,0,1,0,1,1,0,0,1,0,0,1,0,0,0,1,0,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,0,1,0,0},{0,1,0,0,0,1,1,0,0,0,1,1,1,0,1,1,0,0,0,0,1,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,1,0,0,1,1,0,0,1,0,0,0,1,0}};
	int gridRowSize = sizeof(__grid) / sizeof(*__grid);
	int gridColSize = sizeof(*__grid) / sizeof(**__grid);
	int *grid[gridRowSize];
	for (int i = 0; i < gridRowSize; ++i)
		grid[i] = __grid[i];
	printf("67\n%d\n\n", numDistinctIslands(grid, gridRowSize, gridColSize));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

