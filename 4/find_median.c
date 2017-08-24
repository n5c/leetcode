#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2,
				int nums2Size) {
	int *a, *b, asize, bsize;
	int i, j, start, end, total, half;
	double median;

	if (nums1Size == 1 && nums2Size == 1)
		return (((double)nums1[0] + (double)nums2[0]) / (double)2);

	total = nums1Size + nums2Size;
	half = total >> 1;
	if (nums1Size <= nums2Size) {
		a = nums1;
		asize = nums1Size;
		b = nums2;
		bsize = nums2Size;
	} else {
		a = nums2;
		asize = nums2Size;
		b = nums1;
		bsize = nums1Size;
	}

	if (!asize) {
		if (total & 1)
			return b[half];
		return (((double)b[half] + (double)b[half - 1]) /
				(double)2);
	}

	if (!bsize)
		return (double)0;

	start = 0;
	end = asize - 1;
	while (start <= end) {
		i = ((start + end) >> 1);
		j = half - i;
		if (a[i] < b[j - 1])
			start = i + 1;
		else if (i && a[i - 1] > b[j])
			end = i - 1;
		else
			break;
	}

	if ((i == asize - 1) && (a[i] < b[j - 1])) {
		if (total & 1)
			return (double)b[j - 1];
		else if (a[i] < b[j - 2])
			return (((double)b[j - 1] + (double)b[j - 2]) /
					(double)2);
		else
			return (((double)b[j - 1] + (double)a[i]) /
					(double)2);
	}

	median = (double)((a[i] <= b[j]) ? a[i] : b[j]);
	if (!(total & 1)) {
		median += (double)((a[i - 1] >= b[j - 1]) ?
				a[i - 1] : b[j - 1]);
		median /= (double)2;
	}

	return median;
}

void test_case_0(void)
{
	int nums1[] = {1,3};
	int nums2[] = {2};

	printf("2.0\n%f\n\n", findMedianSortedArrays(
				nums1, (sizeof(nums1)/sizeof(nums1[0])),
				nums2, (sizeof(nums2)/sizeof(nums2[0]))));
}

void test_case_1(void)
{
	int nums1[] = {1,2};
	int nums2[] = {3,4};

	printf("2.5\n%f\n\n", findMedianSortedArrays(
				nums1, (sizeof(nums1)/sizeof(nums1[0])),
				nums2, (sizeof(nums2)/sizeof(nums2[0]))));
}

void test_case_2(void)
{
	int nums1[] = {1};
	int nums2[] = {3,4,5};

	printf("3.5\n%f\n\n", findMedianSortedArrays(
				nums1, (sizeof(nums1)/sizeof(nums1[0])),
				nums2, (sizeof(nums2)/sizeof(nums2[0]))));
}

void test_case_3(void)
{
	int nums1[] = {};
	int nums2[] = {1};

	printf("1.0\n%f\n\n", findMedianSortedArrays(
				nums1, (sizeof(nums1)/sizeof(nums1[0])),
				nums2, (sizeof(nums2)/sizeof(nums2[0]))));
}

void test_case_4(void)
{
	int nums1[] = {11,22,33,44,55};
	int nums2[] = {2,4,8,20,30};

	printf("21.0\n%f\n\n", findMedianSortedArrays(
				nums1, (sizeof(nums1)/sizeof(nums1[0])),
				nums2, (sizeof(nums2)/sizeof(nums2[0]))));
}

int main(int argc, char *argv[])
{
	test_case_0();
	test_case_1();
	test_case_2();
	test_case_3();
	test_case_4();
	return 0;
}
