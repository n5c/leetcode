char* reverseString(char* s)
{
	int i, j;
	char tmp;
	for (i = 0; s[i]; i++);
	for (j = (i - 1), i = 0; i < j; i++, j--) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
	return s;
}

