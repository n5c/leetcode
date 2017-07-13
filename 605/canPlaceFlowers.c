#include <leetcode.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n)
{
	int i, j;

	if (!n)
		return true;

	i = 0;
	if (!flowerbed[i]) {
		i++;
		if (i < flowerbedSize) {
			if (!flowerbed[i])
				n--;

		} else {
			n--;

		}

	}

	for (j = 0; i < flowerbedSize && n; i++) {
		if (flowerbed[i]) {
			if (j)
				j = 0;
			continue;

		}
		j++;
		if (j >= 3) {
			j = 1;
			n--;

		}

	}

	if (j >= 2 && n)
		n--;

	if (n)
		return false;

	return true;

}

void tc_0(void)
{
	int flowerbed[] = {0};
	int flowerbedSize = sizeof(flowerbed)/sizeof(*flowerbed);
	printf("true\n%s\n\n",
		canPlaceFlowers(flowerbed, flowerbedSize, 1) ?
		"true" : "false");
}

void tc_1(void)
{
	int flowerbed[] = {0,0};
	int flowerbedSize = sizeof(flowerbed)/sizeof(*flowerbed);
	printf("true\n%s\n\n",
		canPlaceFlowers(flowerbed, flowerbedSize, 1) ?
		"true" : "false");
}

void tc_2(void)
{
	int flowerbed[] = {0,0,0};
	int flowerbedSize = sizeof(flowerbed)/sizeof(*flowerbed);
	printf("true\n%s\n\n",
		canPlaceFlowers(flowerbed, flowerbedSize, 1) ?
		"true" : "false");
}

void tc_3(void)
{
	int flowerbed[] = {0,1};
	int flowerbedSize = sizeof(flowerbed)/sizeof(*flowerbed);
	printf("false\n%s\n\n",
		canPlaceFlowers(flowerbed, flowerbedSize, 1) ?
		"true" : "false");
}

void tc_4(void)
{
	int flowerbed[] = {1,0};
	int flowerbedSize = sizeof(flowerbed)/sizeof(*flowerbed);
	printf("false\n%s\n\n",
		canPlaceFlowers(flowerbed, flowerbedSize, 1) ?
		"true" : "false");
}

void tc_5(void)
{
	int flowerbed[] = {0,0,0};
	int flowerbedSize = sizeof(flowerbed)/sizeof(*flowerbed);
	printf("true\n%s\n\n",
		canPlaceFlowers(flowerbed, flowerbedSize, 2) ?
		"true" : "false");
}

void tc_6(void)
{
	int flowerbed[] = {1,0,0,0,1};
	int flowerbedSize = sizeof(flowerbed)/sizeof(*flowerbed);
	printf("true\n%s\n\n",
		canPlaceFlowers(flowerbed, flowerbedSize, 1) ?
		"true" : "false");
}

void tc_7(void)
{
	int flowerbed[] = {1,0,0,0,0,1};
	int flowerbedSize = sizeof(flowerbed)/sizeof(*flowerbed);
	printf("false\n%s\n\n",
		canPlaceFlowers(flowerbed, flowerbedSize, 2) ?
		"true" : "false");
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	tc_2();
	tc_3();
	tc_4();
	tc_5();
	tc_6();
	tc_7();
	return 0;
}

