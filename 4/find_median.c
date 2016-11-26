#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2,
			      int nums2Size)
{
	double median;
	return median;
}


void test_case_0(void)
{
	int nums1[] = {7,10,12,13,15,16};
	int nums2[] = {1,3,4,5,14};

	printf("case 0 = %f\n", findMedianSortedArrays(
				nums1, (sizeof(nums1)/sizeof(nums1[0])),
				nums2, (sizeof(nums2)/sizeof(nums2[0]))));
}

void test_case_1(void)
{
	int nums1[] = {};
	int nums2[] = {1,3,4,5,14};

	printf("case 1 = %f\n", findMedianSortedArrays(
				nums1, (sizeof(nums1)/sizeof(nums1[0])),
				nums2, (sizeof(nums2)/sizeof(nums2[0]))));
}

int main(int argc, char *argv[])
{
	// test_case_0();
	test_case_1();
	return 0;
}
