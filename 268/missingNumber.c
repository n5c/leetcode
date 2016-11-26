int missingNumber(int* nums, int numsSize)
{
	int i, missing;
	if (numsSize & 1)
		missing = ((numsSize + 1) >> 1) * (numsSize);
	else
		missing = (numsSize >> 1) * (numsSize + 1);

	for (i = 0; i < numsSize; i++)
		missing -= nums[i];

	return missing;
}

