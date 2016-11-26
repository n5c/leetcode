#include <stdio.h>

char* reverseVowels(char* s)
{
	int i, j, k;
	char chk[250] = {0};

	if (!s)
		return NULL;
	if (!*s)
		return s;

	chk['a'] = 1;
	chk['e'] = 1;
	chk['i'] = 1;
	chk['o'] = 1;
	chk['u'] = 1;
	chk['A'] = 1;
	chk['E'] = 1;
	chk['I'] = 1;
	chk['O'] = 1;
	chk['U'] = 1;

	j = 0;
	while (s[j]) j++;
	j--;

	i = 0;
	while (1) {
		while ((i < j) && !chk[s[i]])
			i++;

		while ((i < j) && !chk[s[j]])
			j--;

		if (i >= j)
			break;
		k = s[i];
		s[i] = s[j];
		s[j] = k;
		i++;
		j--;
	}

	return s;
}

void test_case_0()
{
	char s[1000];

	snprintf(s, 1000, "hello");
	printf("holle\n");
	printf("%s\n", reverseVowels(s));

	snprintf(s, 1000, "1234567890aioioioeuiaiuaiuaaiudiaufiuafioueiouafoihgajdfjajf");
	printf("holle\n");
	printf("%s\n", reverseVowels(s));
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

