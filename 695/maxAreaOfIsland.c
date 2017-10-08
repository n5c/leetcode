#include <leetcode.h>

int calArea(int **grid, int gridRowSize, int gridColSize, int x, int y)
{
	int area = 1;
	grid[x][y] = 0;
	if (((x - 1) >= 0) && grid[x - 1][y])
		area += calArea(grid, gridRowSize, gridColSize, x - 1, y);
	if (((x + 1) < gridRowSize) && grid[x + 1][y])
		area += calArea(grid, gridRowSize, gridColSize, x + 1, y);
	if (((y - 1) >= 0) && grid[x][y - 1])
		area += calArea(grid, gridRowSize, gridColSize, x, y - 1);
	if (((y + 1) < gridColSize) && grid[x][y + 1])
		area += calArea(grid, gridRowSize, gridColSize, x, y + 1);
	return area;
}

int maxAreaOfIsland(int** grid, int gridRowSize, int gridColSize)
{
	int max = 0, area;
	for (int i = 0; i < gridRowSize; ++i) {
		for (int j = 0; j < gridColSize; ++j) {
			if (!grid[i][j])
				continue;
			area = calArea(grid, gridRowSize, gridColSize, i, j);
			if (area > max)
				max = area;
		}
	}
	return max;
}

void tc_0(void)
{
	int __grid[][13] = {{0,0,1,0,0,0,0,1,0,0,0,0,0}, {0,0,0,0,0,0,0,1,1,1,0,0,0}, {0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0}, {0,1,0,0,1,1,0,0,1,1,1,0,0}, {0,0,0,0,0,0,0,0,0,0,1,0,0}, {0,0,0,0,0,0,0,1,1,1,0,0,0}, {0,0,0,0,0,0,0,1,1,0,0,0,0}};
	int gridRowSize = sizeof(__grid) / sizeof(*__grid);
	int gridColSize = sizeof(*__grid) / sizeof(**__grid);
	int *grid[gridRowSize];
	for (int i = 0; i < gridRowSize; ++i)
		grid[i] = __grid[i];
	printf("6\n%d\n\n", maxAreaOfIsland(grid, gridRowSize, gridColSize));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

