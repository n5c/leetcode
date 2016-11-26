int singleNumber(int* nums, int numsSize)
{
#if 0
	int i, j, k, l;

	/* heapify */
	for (i = 1; i < numsSize; i++) {
		j = i;
		while (j) {
			k = (((j + 1) >> 1) - 1);
			if (nums[k] >= nums[j])
				break;
			l = nums[j];
			nums[j] = nums[k];
			nums[k] = l;
			j = k;
		}
	}

	/* heapsort */
	for (i = (numsSize - 1); i; i--) {
		l = nums[i];
		nums[i] = nums[0];
		nums[0] = l;

		j = 0;
		while (j < i) {
			k = (((j + 1) << 1) - 1);
			k = ((k >= i) ? -1 :
					(((k + 1) >= i) ? k :
					 ((nums[k+1] > nums[k]) ? k+1 : k)));
			if (k == -1)
				break;
			if (nums[k] <= nums[j])
				break;
			l = nums[j];
			nums[j] = nums[k];
			nums[k] = l;
			j = k;
		}
	}

	for (i = 0; i < numsSize; i+=2) {
		if ((i + 1) >= numsSize)
			break;
		if (nums[i] != nums[i + 1])
			break;
	}

	return nums[i];
#endif

#if 0
	int i, j, k, l;
	int bytechk[4][256] = {0};

	for (i = 0; i < numsSize; i++) {
		bytechk[0][nums[i] & 0xff]++;
		bytechk[1][(nums[i] >> 8) & 0xff]++;
		bytechk[2][(nums[i] >> 16) & 0xff]++;
		bytechk[3][(nums[i] >> 24) & 0xff]++;
	}

	for (i = 0, j = 0; i < 256; i++) {
		if (bytechk[0][i] & 1)
			j |= i;
		if (bytechk[1][i] & 1)
			j |= (i << 8);
		if (bytechk[2][i] & 1)
			j |= (i << 16);
		if (bytechk[3][i] & 1)
			j |= (i << 24);
	}

	return j;
#endif
	int i = 0, result = 0;
	while (i < numsSize)
		result ^= nums[i++];
	return result;
}

