#include <leetcode.h>

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
	struct ListNode *root, *node, *tmp;
	int i, j, k, l;

	for (i = 0; i < listsSize; i++) {
		if (!lists[i])
			continue;
		lists[0] = lists[i];
		break;
	}

	if (i >= listsSize)
		return NULL;

	for (i = i + 1, l = 1; i < listsSize; i++) {
		if (!lists[i])
			continue;
		lists[l] = lists[i];
		j = l++;
		while (j) {
			k = (((j + 1) >> 1) - 1);
			if (lists[k]->val <= lists[j]->val)
				break;
			tmp = lists[k];
			lists[k] = lists[j];
			lists[j] = tmp;
			j = k;
		}
	}
	listsSize = l;

	if (!listsSize)
		return NULL;

	if (listsSize == 1)
		return lists[0];

	root = lists[0];
	lists[0] = lists[0]->next;
	node = root;
	while (1) {
		if (!lists[0]) {
			lists[0] = lists[listsSize - 1];
			listsSize--;
			if (listsSize <= 1) {
				node->next = lists[0];
				break;
			}
		}

		j = 0;
		while (1) {
			k = (((j + 1) << 1) - 1);
			if (k >= listsSize)
				break;
			if (k + 1 < listsSize) {
				if (lists[k]->val > lists[k + 1]->val)
					k++;
			}
			if (lists[k]->val >= lists[j]->val)
				break;
			tmp = lists[k];
			lists[k] = lists[j];
			lists[j] = tmp;
			j = k;
		}

		node->next = lists[0];
		node = lists[0];
		lists[0] = lists[0]->next;
	}

	return root;
}

void tc_0(void)
{
	struct ListNode *lists[] = {NULL, NULL, NULL};
	int listsSize = sizeof(lists) / sizeof(*lists);
	struct ListNode *l = mergeKLists(lists, listsSize);
	if (!l) {
		printf("null\n");
		return;
	}

	printf("%d", l->val);
	l = l->next;
	while (l) {
		printf(",%d", l->val);
		l = l->next;
	}
	printf("\n\n");
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

