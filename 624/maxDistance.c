#include <leetcode.h>

int maxDistance(int** arrays, int arraysRowSize, int *arraysColSizes)
{
	int i, j, maxd, dis, _min, _max;

	maxd = INT_MIN;
	_min = arrays[0][0];
	_max = arrays[0][arraysColSizes[0] - 1];
	for (i = 1; i < arraysRowSize; i++) {
		dis = arrays[i][arraysColSizes[i] - 1] - _min;
		if (dis > maxd)
			maxd = dis;

		dis = _max - arrays[i][0];
		if (dis > maxd)
			maxd = dis;

		if (arrays[i][arraysColSizes[i] - 1] > _max)
			_max = arrays[i][arraysColSizes[i] - 1];

		if (arrays[i][0] < _min)
			_min = arrays[i][0];
	}

	return maxd;
}

void tc_0(void)
{
	int _arrays0[] = {1,2,3};
	int _arrays1[] = {4,5};
	int _arrays2[] = {1,2,3};
	int *arrays[] = {_arrays0,_arrays1,_arrays2};
	int arraysRowSize = sizeof(arrays)/sizeof(*arrays);
	int arraysColSize[] = {
		sizeof(_arrays0)/sizeof(*_arrays0),
		sizeof(_arrays1)/sizeof(*_arrays1),
		sizeof(_arrays2)/sizeof(*_arrays2)
	};
	printf("4\n%d\n", maxDistance(arrays, arraysRowSize, arraysColSize));
}

void tc_1(void)
{
	int _arrays0[] = {3};
	int _arrays1[] = {5};
	int *arrays[] = {_arrays0,_arrays1};
	int arraysRowSize = sizeof(arrays)/sizeof(*arrays);
	int arraysColSize[] = {
		sizeof(_arrays0)/sizeof(*_arrays0),
		sizeof(_arrays1)/sizeof(*_arrays1),
	};
	printf("2\n%d\n", maxDistance(arrays, arraysRowSize, arraysColSize));
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	return 0;
}

