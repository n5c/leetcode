#include <leetcode.h>

bool judgeCircle(char* moves)
{
	int x = 0, y = 0;
	char c;
	while ((c = *(moves++))) {
		if (c == 'R')
			x++;
		else if (c == 'L')
			x--;
		else if (c == 'U')
			y++;
		else if (c == 'D')
			y--;

	}
	return (!x && !y);

}

void tc_0(void)
{
	char moves[] = "UULLLRRRDD";
	printf("true\n");
	printf("%s\n\n", judgeCircle(moves) ?
			"true" : "false");
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

