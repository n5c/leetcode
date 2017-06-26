#include <leetcode.h>

int countSegments(char* s)
{
	int i = 0, count = 0, nospace = 0;
	while (s[i]) {
		if (s[i] == ' ') {
			if (nospace) {
				count++;
				nospace = 0;
			}
		} else {
			if (!nospace)
				nospace = 1;
		}
		i++;
	}

	if (nospace)
		count++;

	return count;
}

void tc_0(void)
{
	char s[] = "Hello, my name is John";
	printf("5: %d\n", countSegments(s));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

