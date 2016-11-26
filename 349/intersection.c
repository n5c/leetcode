#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
	int *_nums1, _size1, *_nums2, _size2, *_array;
	int i, j, k, l, m;

	if (nums1Size < nums2Size) {
		_nums1 = nums2;
		_size1 = nums2Size;
		_nums2 = nums1;
		_size2 = nums1Size;
	} else {
		_nums1 = nums1;
		_size1 = nums1Size;
		_nums2 = nums2;
		_size2 = nums2Size;
	}

	// heapify
	for (i = 1; i < _size1; i++) {
		j = i;
		while (j) {
			k = ((j + 1) >> 1) - 1;
			if (_nums1[k] >= _nums1[j])
				break;
			l = _nums1[j];
			_nums1[j] = _nums1[k];
			_nums1[k] = l;
			j = k;
		}
	}
	// sort
	for (i = _size1 - 1; i > 0; i--) {
		l = _nums1[0];
		_nums1[0] = _nums1[i];
		_nums1[i] = l;

		j = 0;
		while (j < i) {
			k = ((j + 1) << 1) - 1;
			if (k >= i)
				break;
			if (((k + 1) < i) && (_nums1[k + 1] > _nums1[k]))
				k++;
			if (_nums1[k] <= _nums1[j])
				break;
			l = _nums1[k];
			_nums1[k] = _nums1[j];
			_nums1[j] = l;
			j = k;
		}
	}

	// heapify
	for (i = 1; i < _size2; i++) {
		j = i;
		while (j) {
			k = ((j + 1) >> 1) - 1;
			if (_nums2[k] >= _nums2[j])
				break;
			l = _nums2[j];
			_nums2[j] = _nums2[k];
			_nums2[k] = l;
			j = k;
		}
	}
	// sort
	for (i = _size2 - 1; i > 0; i--) {
		l = _nums2[0];
		_nums2[0] = _nums2[i];
		_nums2[i] = l;

		j = 0;
		while (j < i) {
			k = ((j + 1) << 1) - 1;
			if (k >= i)
				break;
			if (((k + 1) < i) && (_nums2[k + 1] > _nums2[k]))
				k++;
			if (_nums2[k] <= _nums2[j])
				break;
			l = _nums2[k];
			_nums2[k] = _nums2[j];
			_nums2[j] = l;
			j = k;
		}
	}

	for (i = 0, m = 0; i < _size2;) {
		j = 0;
		k = _size1 - 1;
		while (j <= k) {
			l = (j + k) >> 1;
			if (_nums1[l] == _nums2[i])
				break;
			if (_nums1[l] > _nums2[i])
				k = l - 1;
			else /* if (_nums1[l] < _nums2[i]) */
				j = l + 1;
		}
		if (j <= k) {
			_nums2[m] = _nums2[i];
			m++;
			j = i + 1;
			while ((j < _size2) && (_nums2[j] == _nums2[i])) j++;
			i = j;
		} else {
			i++;
		}
	}

	if (!m) {
		*returnSize = 0;
		return NULL;
	}

	_array = malloc(sizeof(*_array) * m);
	for (i = 0; i < m; i++)
		_array[i] = _nums2[i];

	*returnSize = m;

	return _array;
}

void print(int *nums, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		printf("%d", nums[i]);
		if (i + 1 < size)
			printf(",");
	}
	printf("\n");
}

void test_case_0(void)
{
	int nums1[] = {1,2,3,4,5,6,7,8,9,10,10,11,11,11,12,12,1,13};
	int size1 = sizeof(nums1)/sizeof(*nums1);
	int nums2[] = {3,6,9,1,11,11};
	int size2 = sizeof(nums2)/sizeof(*nums2);
	int *nums, size;
	nums = intersection(nums1, size1, nums2, size2, &size);
	printf("1: 1,2,3,4,5,6,7,8,9,10,10,11,11,11,12,12,1,13\n");
	printf("2: 3,6,9,1,11,11\n");
	printf("expect: 1,3,6,9,11\n");
	print(nums, size);
	if (nums)
		free(nums);
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

