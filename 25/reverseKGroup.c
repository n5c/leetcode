#include <leetcode.h>

struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
	int i;
	struct ListNode *node, *_head, **tail;

	if (!head)
		return NULL;

	if (k <= 1)
		return head;

	_head = head;
	tail = &(_head->next);
	for (i = 1; *tail && i < k; i++) {
		node = *tail;
		*tail = node->next;
		node->next = _head;
		_head = node;

	}

	if (i < k) {
		tail = &(_head->next);
		while (*tail) {
			node = *tail;
			*tail = node->next;
			node->next = _head;
			_head = node;

		}
		return _head;

	}

	*tail = reverseKGroup(*tail, k);

	return _head;

}

void tc_0(void)
{
	struct ListNode l[] = {
		{1,&l[1]},
		{2,&l[2]},
		{3,&l[3]},
		{4,&l[4]},
		{5,&l[5]},
		{6,&l[6]},
		{7,&l[7]},
		{8,NULL}
	};
	struct ListNode *node = reverseKGroup(l, 3);
	printf("3,2,1,6,5,4,7,8\n");
	while (node) {
		printf("%d", node->val);
		if (node->next)
			printf(",");
		node = node->next;
	}
	printf("\n\n");
}

int main(int argc, char *argv[])
{
	tc_0();
	return 0;
}

