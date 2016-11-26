int numberOfArithmeticSlices(int* A, int ASize)
{
	int i, j, nums, sum;
	for (i = 0, sum = 0; i < ASize - 2; i++) {
		if ((A[i] - A[i + 1]) != (A[i + 1] - A[i + 2]))
			continue;
		nums = 1;
		for (j = i + 1; j < ASize - 2; j++) {
			if ((A[j] - A[j + 1]) != (A[j + 1] - A[j + 2]))
				break;
			nums++;
		}

		if (nums & 1)
			sum += (((nums + 1) >> 1) * nums);
		else
			sum += ((nums >> 1) * (nums + 1));
		i = j;
	}

	return sum;
}

