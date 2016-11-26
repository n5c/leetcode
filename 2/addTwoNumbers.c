#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
#if 0
	struct ListNode *first, *node, *temp;

	first = node = calloc(1, sizeof(*node));

	while (l1 || l2) {
		if (l1) {
			node->val += l1->val;
			l1 = l1->next;
		}

		if (l2) {
			node->val += l2->val;
			l2 = l2->next;
		}

		if (l1 || l2 || (node->val >= 10)) {
			temp = calloc(1, sizeof(*node));
			if (node->val >= 10) {
				node->val -= 10;
				temp->val += 1;
			}
			node->next = temp;
			node = temp;
		}
	}

	return first;
#endif

	struct ListNode *root, *node, **next;
	int c;

	next = &root;
	c = 0;
	while (l1 || l2) {
		node = malloc(sizeof(*node));
		node->val = c;
		node->next = NULL;

		if (l1) {
			node->val += l1->val;
			l1 = l1->next;
		}

		if (l2) {
			node->val += l2->val;
			l2 = l2->next;
		}

		c = (node->val / 10);
		node->val %= 10;
		*next = node;
		next = &(node->next);
	}

	if (c) {
		node = malloc(sizeof(*node));
		node->val = c;
		node->next = NULL;
		*next = node;
	}

	return root;
}

void test_case_0()
{
}

int main(int argc, char *argv[])
{
	test_case_0();
	return 0;
}

