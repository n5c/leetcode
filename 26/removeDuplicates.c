int removeDuplicates(int* nums, int numsSize) {
	int i, count = 1;

	if (!numsSize)
		return 0;

	for (i = 1; i < numsSize; i++) {
		if (nums[i] == nums[i-1])
			continue;
		nums[count] = nums[i];
		count++;
	}

	return count;
}


