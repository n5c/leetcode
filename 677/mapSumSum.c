#include <leetcode.h>

typedef struct __MapSum
{
	struct __MapSum *next[256];
	int sum;
	int end;
} MapSum;

/** Initialize your data structure here. */
MapSum* mapSumCreate()
{
	MapSum *sums = calloc(1, sizeof(*sums));
	return sums;
}

void mapSumInsert(MapSum* obj, char* key, int val)
{
	int i;
	MapSum **node;
	for (i = 0, node = &obj; key[i] && *node; i++)
		node = &((*node)->next[key[i]]);
	if (!key[i] && (*node) && (*node)->end)
		val -= (*node)->sum;
	for (i = 0, node = &obj; key[i]; i++) {
		node = &((*node)->next[key[i]]);
		if (!(*node))
			*node = calloc(1, sizeof(MapSum));
		(*node)->sum += val;
	}
	(*node)->end = 1;
}

int mapSumSum(MapSum* obj, char* prefix)
{
	int i;
	MapSum *node;
	for (i = 0, node = obj; prefix[i] && node; i++)
		node = node->next[prefix[i]];
	if (!node)
		return 0;
	return node->sum;
}

void mapSumFree(MapSum* obj) {
	if (!obj)
		return;
	for (int i = 0; i < 256; i++)
		mapSumFree(obj->next[i]);
	free(obj);
}

void tc_0(void)
{
	MapSum *obj;
	obj = mapSumCreate();
	mapSumInsert(obj, "apple", 3);
	printf("%d\n", mapSumSum(obj, "ap"));
	mapSumInsert(obj, "app", 2);
	printf("%d\n", mapSumSum(obj, "ap"));
	mapSumFree(obj);
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

