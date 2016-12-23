#include <leetcode.h>

bool isIsomorphic(char* s, char* t)
{
	char rpls[256] = {0}, rplt[256] = {0};
	for (int i = 0; s[i]; i++) {
		if (!rpls[s[i]]) {
			rpls[s[i]] = t[i];
			if (rplt[t[i]] && rplt[t[i]] != s[i])
				return false;
			rplt[t[i]] = s[i];
		}
		else if (rpls[s[i]] != t[i])
			return false;
	}
	return true;
}

void tc_0(void)
{
	char s[] = "paper", t[] = "title";
	printf("true\n");
	printf("%s\n", (isIsomorphic(s, t) ? "true" : "false"));
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

