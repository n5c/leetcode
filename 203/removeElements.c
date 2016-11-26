#include <stdio.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode **next, *node;

	if (head == NULL)
		return NULL;

	next = &head;
	while (*next) {
		if ((*next)->val == val) {
			node = *next;
			while (node && (node->val == val))
				node = node->next;
			*next = node;
			continue;
		}
		next = &((*next)->next);
	}

	return head;
}

