#include <leetcode.h>

int threeSumClosest(int* nums, int numsSize, int target)
{
	int cmp(const void *a, const void *b) {
		const int *ia = a;
		const int *ib = b;
		return (*ia - *ib);
	}

	qsort(nums, numsSize, sizeof(*nums), cmp);

	int i, j, k, l, min, minDiff = INT_MAX;

	for (i = 0; i < numsSize; i++) {
		j = numsSize - 1;
		/* while (i < j && nums[i] == nums[i + 1]) i++; */
		for (; j > i; j--) {
			/* while (j > i && nums[j] == nums[j - 1]) j--; */
			k = target - (nums[i] + nums[j]);
			if (k < nums[i]) {
				if (i + 2 <= j) {
					l = abs(target - nums[i] - nums[i + 1] - nums[i + 2]);
					if (l < minDiff) {
						minDiff = l;
						min = nums[i] + nums[i + 1] + nums[i + 2];
					}
				}
				numsSize = j;
				continue;
			} else if (k > nums[j]) {
				if (i  <= j - 2) {
					l = abs(target - nums[j - 2] - nums[j - 1] - nums[j]);
					if (l < minDiff) {
						minDiff = l;
						min = nums[j - 2] + nums[j - 1] + nums[j];
					}
				}
				break;
			} /* else { */

			int mid = -1, start = i + 1, end = j - 1;
			while (start <= end) {
				mid = (start + end) >> 1;
				if (nums[mid] == k)
					break;
				else if (nums[mid] < k)
					start = mid + 1;
				else
					end = mid - 1;
			}

			if (mid == i || mid == j || mid == -1)
				continue;

			l = abs(k - nums[mid]);
			if (l < minDiff) {
				minDiff = l;
				min = nums[i] + nums[mid] + nums[j];
			}

			if (mid - 1 != i) {
				l = abs(k - nums[mid - 1]);
				if (l < minDiff) {
					minDiff = l;
					min = nums[i] + nums[mid - 1] + nums[j];
				}
			}

			if (mid + 1 != j) {
				l = abs(k - nums[mid + 1]);
				if (l < minDiff) {
					minDiff = l;
					min = nums[i] + nums[mid + 1] + nums[j];
				}
			}

			if (!minDiff)
				return target;
			/* } */
		}
	}

	return min;
}

void tc_0(void)
{
	int nums[] = {0,0,0};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int target = 1;

	printf("0\n");
	printf("%d\n\n", threeSumClosest(nums, numsSize, target));
}

void tc_1(void)
{
	int nums[] = {-1,2,1,-4,7,8,-13,-10,11,7};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int target = 11;

	printf("11\n");
	printf("%d\n\n", threeSumClosest(nums, numsSize, target));
}

void tc_2(void)
{
	int nums[] = {-1,2,1,-4,7,8,-13,-10,11,7};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int target = 30;

	printf("26\n");
	printf("%d\n\n", threeSumClosest(nums, numsSize, target));
}

void tc_3(void)
{
	int nums[] = {-1,2,1,-4,7,8,-13,-10,11,7};
	int numsSize = sizeof(nums)/sizeof(*nums);
	int target = -30;

	printf("-27\n");
	printf("%d\n\n", threeSumClosest(nums, numsSize, target));
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	tc_2();
	tc_3();
	return 0;
}

