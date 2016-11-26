int removeElement(int* nums, int numsSize, int val)
{
	int i, j;

	if (!numsSize)
		return 0;

	for (i = 0, j = (numsSize - 1); i <= j; i++) {
		if (nums[i] != val)
			continue;
		while (nums[j] == val) j--;
		if (i > j) break;
		nums[i] = nums[j];
		j--;
	}

	return (j + 1);
}

