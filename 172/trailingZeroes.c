int trailingZeroes(int n)
{
	int i, j;

	i = 0;
	while (n) {
		j = n / 5;
		i += j;
		n = j;
	}

	return i;
}

