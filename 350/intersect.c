#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
	int *_nums1, _size1, *_nums2, _size2, *array;
	int i, j, k, l;

	if (!nums1Size || !nums2Size)
		return NULL;

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

	for (i = 0, k = 0; i < _size2;) {
		for (j = k; j < _size1; j++) {
			if (_nums2[i] == _nums1[j])
				break;
		}

		if (j < _size1) {
			l = _nums2[k];
			_nums2[k] = _nums2[i];
			_nums2[i] = l;
			l = _nums1[k];
			_nums1[k] = _nums1[j];
			_nums1[j] = l;
			k++;
			i++;
		} else {
			l = _nums2[i];
			_nums2[i] = _nums2[--_size2];
			for (j = (i + 1); j < _size2; j++) {
				if (_nums2[j] != l)
					continue;
				_nums2[j] = _nums2[--_size2];
			}
		}
	}

	if (!k)
		return NULL;

	array = malloc(sizeof(*array) * k);
	for (i = 0; i < k; i++)
		array[i] = _nums2[i];

	*returnSize = k;

	return array;
}

