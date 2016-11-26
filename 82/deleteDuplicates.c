#include <stdio.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head)
{
	struct ListNode **next, *node;

	if (head == NULL)
		return NULL;

	next = &head;
	while (*next && (*next)->next) {
		if ((*next)->val == (*next)->next->val) {
			node = (*next)->next;
			while (node) {
				if (node->val != (*next)->val)
					break;
				node = node->next;
			}
			*next = node;
		}
		next = &((*next)->next);
	}
	return head;
}


