#include <leetcode.h>

int maxArea(int* height, int heightSize)
{
	int i, j, area, max;

	for (i = 0, j = heightSize - 1, max = 0; i < j;) {
		area = (j - i) * (height[i] <= height[j] ?
				  height[i] : height[j]);
		if (area > max)
			max = area;
		if (height[i] <= height[j])
			i++;
		else
			j--;
	}

	return max;
}

int maxArea2(int* height, int heightSize)
{
	int i, j, area, max, heightest;
	int *farend;

	for (i = 0, heightest = -1; i < heightSize; i++) {
		if (height[i] > heightest)
			heightest = height[i];
	}

	if (heightest == -1)
		return 0;

	farend = malloc(sizeof(*farend) * (heightest + 1));
	for (i = 0; i <= height[0]; i++)
		farend[i] = 0;
	for (i = (height[0] + 1); i <= heightest; i++)
		farend[i] = -1;
	max = 0;
	for (i = 1; i < heightSize; i++) {
		if (!height[i])
			continue;
		if (farend[height[i]] == -1) {
			for (j = height[i]; farend[j] == -1; j--)
				farend[j] = i;
			continue;
		}
		area = (height[i] * (i - farend[height[i]]));
		if (area > max)
			max = area;
	}

	for (i = 0; i <= height[heightSize - 1]; i++)
		farend[i] = heightSize - 1;
	for (i = (height[heightSize - 1] + 1); i <= heightest; i++)
		farend[i] = -1;
	for (i = heightSize - 2; i >= 0; i--) {
		if (!height[i])
			continue;
		if (farend[height[i]] == -1) {
			for (j = height[i]; farend[j] == -1; j--)
				farend[j] = i;
			continue;
		}
		area = (height[i] * (farend[height[i]] - i));
		if (area > max)
			max = area;
	}

	free(farend);

	return max;
}

void tc_0()
{
	int height[] = {4,1,2,3,4,5,1,2,3,4};
	int heightSize = sizeof(height)/sizeof(*height);
	printf("36\n");
	printf("%d\n\n", maxArea(height, heightSize));
}

void tc_1()
{
	int height[] = {1,1};
	int heightSize = sizeof(height)/sizeof(*height);
	printf("1\n");
	printf("%d\n\n", maxArea(height, heightSize));
}

void tc_2()
{
	int height[] = {0,0};
	int heightSize = sizeof(height)/sizeof(*height);
	printf("0\n");
	printf("%d\n\n", maxArea(height, heightSize));
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	tc_2();
	return 0;
}

