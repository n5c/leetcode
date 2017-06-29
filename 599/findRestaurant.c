#include <leetcode.h>

/* djb2 */
unsigned short hash(unsigned char *str)
{
	unsigned short hash = 5381;
	short c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
}

int cmp(const void *a, const void *b)
{
	char *sa = ((char *)a);
	char *sb = ((char *)b);
	int diff;

	while (*sa && *sb) {
		diff = *sa - *sb;
		if (diff)
			return diff;
		sa++;
		sb++;
	}

	if (*sa)
		return 1;
	if (*sb)
		return -1;
	return 0;
}

/**
 *  * Return an array of size *returnSize.
 *   * Note: The returned array must be malloced, assume caller calls free().
 *    */
char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize)
{
	int i, min, index, count, least[list1Size];
	unsigned short h;
	char **rlist;
	struct {
		char str[32];
		int indexsum;
	} hashtbl[65536] = {0};

	for (i = 0; i < list1Size; i++) {
		h = hash((unsigned char *)list1[i]);
		while(hashtbl[h].str[0])
			h++;
		strcpy(hashtbl[h].str, list1[i]);
		hashtbl[h].indexsum = i;
	}

	count = 0;
	min = INT_MAX;
	for (i = 0; i < list2Size; i++) {
		h = hash((unsigned char *)list2[i]);
		if (!hashtbl[h].str[0])
			continue;
		while (hashtbl[h].str[0] && cmp(list2[i], hashtbl[h].str))
			h++;
		if (!hashtbl[h].str[0])
			continue;
		hashtbl[h].indexsum += i;
		if (hashtbl[h].indexsum < min) {
			min = hashtbl[h].indexsum;
			count = 0;
			least[count++] = i;
		} else if (hashtbl[h].indexsum == min) {
			least[count++] = i;
		}
	}

	*returnSize = count;
	rlist = malloc(sizeof(*rlist) * count);
	for (i = 0; i < count; i++)
		rlist[i] = strdup(list2[least[i]]);

	return rlist;
}

void tc_0(void)
{
	char *list1[] = {"Shogun","Tapioca Express","Burger King","KFC"};
	int list1Size = sizeof(list1)/sizeof(*list1);
	char *list2[] = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};
	int list2Size = sizeof(list2)/sizeof(*list2);
	int returnSize;
	char **res = findRestaurant(list1, list1Size, list2, list2Size, &returnSize);
	printf("Shogun\n");
	for (int i = 0; i < returnSize; i++) {
		if (i)
			printf(", ");
		printf("%s", res[i]);
	}
	printf("\n");
	free(res);
}

void tc_1(void)
{
	char *list1[] = {"Shogun","Tapioca Express","Burger King","KFC"};
	int list1Size = sizeof(list1)/sizeof(*list1);
	char *list2[] = {"KNN","KFC","Burger King","Tapioca Express","Shogun"};
	int list2Size = sizeof(list2)/sizeof(*list2);
	int returnSize;
	char **res = findRestaurant(list1, list1Size, list2, list2Size, &returnSize);
	printf("KFC, Burger King, Tapioca Express, Shogun\n");
	for (int i = 0; i < returnSize; i++) {
		if (i)
			printf(", ");
		printf("%s", res[i]);
	}
	printf("\n");
	free(res);
}

void tc_2(void)
{
	char *list1[] = {"vacag","KFC"};
	int list1Size = sizeof(list1)/sizeof(*list1);
	char *list2[] = {"fvo","xrljq","jrl","KFC"};
	int list2Size = sizeof(list2)/sizeof(*list2);
	int returnSize;
	char **res = findRestaurant(list1, list1Size, list2, list2Size, &returnSize);
	printf("KFC\n");
	for (int i = 0; i < returnSize; i++) {
		if (i)
			printf(", ");
		printf("%s", res[i]);
	}
	printf("\n");
	free(res);
}

int main(int argc, char *argv[])
{
	tc_0();
	tc_1();
	tc_2();
	return 0;
}

