#include <leetcode.h>

int islandPerimeter(int** grid, int gridRowSize, int gridColSize)
{
	int i, j, perimeter, chk;

	chk = 2;
	perimeter = 0;
	for (j = 0; j < gridColSize; j++) {
		if (grid[0][j]) {
			perimeter += chk + 1;
			chk = 0;
		} else {
			chk = 2;
		}
	}

	for (i = 1; i < gridRowSize; i++) {
		chk = 2;
		for (j = 0; j < gridColSize; j++) {
			if (grid[i][j]) {
				perimeter += chk + !grid[i - 1][j];
				chk = 0;
			} else {
				perimeter += grid[i - 1][j];
				chk = 2;
			}
		}
	}

	i--;
	for (j = 0; j < gridColSize; j++) {
		if (grid[i][j])
			perimeter++;
	}

	return perimeter;
}

void tc_2(void)
{
	int _grid[][4] = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
	int *grid[] = {_grid[0], _grid[1], _grid[2], _grid[3]};
	int gridRowSize = sizeof(_grid)/sizeof(*_grid);
	int gridColSize = sizeof(*_grid)/sizeof(**_grid);
	printf("%d\n", islandPerimeter(grid, gridRowSize, gridColSize));
}

void tc_1(void)
{
	int _grid[][1] = {{0},{1},{1}};
	int *grid[] = {_grid[0], _grid[1], _grid[2]};
	int gridRowSize = sizeof(_grid)/sizeof(*_grid);
	int gridColSize = sizeof(*_grid)/sizeof(**_grid);
	printf("%d\n", islandPerimeter(grid, gridRowSize, gridColSize));
}

void tc_0(void)
{
	int _grid[][3] = {{1,1,1}, {1,0,1}};
	int *grid[] = {_grid[0], _grid[1]};
	int gridRowSize = sizeof(_grid)/sizeof(*_grid);
	int gridColSize = sizeof(*_grid)/sizeof(**_grid);
	printf("%d\n", islandPerimeter(grid, gridRowSize, gridColSize));
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	tc_2();
	return 0;
}

